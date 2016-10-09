#include <iostream>
#include <cmath>
using namespace std;

#define X 0
#define Y 1
#define Z 2

typedef struct Vertex *tVertex;
typedef struct Edge *tEdge;
typedef struct Face *tFace;

struct Vertex {
	double v[3];
	int vnum;
	bool onhull, processed;
	tEdge duplicate;	        /* pointer to incident cone edge (or NULL) */
	tVertex next, prev;
};

struct Edge {
	tFace adjface[2];
	tVertex endpts[2];
	tFace newface;            /* pointer to incident cone face. */
	bool remove;		/* T iff edge should be remove. */
	tEdge next, prev;
};

struct Face {
	tEdge edge[3];
	tVertex vertex[3];
	bool visible;	        /* T iff face visible from new point. */
	tFace next, prev;
};

tVertex vertices = NULL;
tEdge edges    	 = NULL;
tFace faces    	 = NULL;

#define ADD(head, p)  if (head)  { \
	p->next = head; \
	p->prev = head->prev; \
	head->prev = p; \
	p->prev->next = p; \
} \
else { \
	head = p; \
	head->next = head->prev = p; \
}

#define DELETE(head, p) if (head)  { \
	if (head == head->next) \
	head = NULL;  \
	else if (p == head) \
	head = head->next; \
	p->next->prev = p->prev;  \
	p->prev->next = p->next;  \
	delete (p); \
} 

const double EPS = 1e-10;

int sgn(double d) {
	return d < -EPS ? -1 : d > EPS;
}

tVertex	MakeNullVertex(void) {
	tVertex  v = new Vertex;
	v->duplicate = NULL;
	v->onhull = false;
	v->processed = false;
	ADD(vertices, v);
	return v;
}

tEdge 	MakeNullEdge(void) {
	tEdge e = new Edge;
	e->adjface[0] = e->adjface[1] = e->newface = NULL;
	e->endpts[0] = e->endpts[1] = NULL;
	e->remove = false;
	ADD(edges, e);
	return e;
}

tFace MakeNullFace(void) {
	tFace f = new Face;
	for (int i = 0; i < 3; ++i) {
		f->edge[i] = NULL;
		f->vertex[i] = NULL;
	}
	f->visible = false;
	ADD(faces, f);
	return f;
}

tFace MakeFace(tVertex v0, tVertex v1, tVertex v2, tFace fold) {
	tEdge e0, e1, e2;

	if (!fold) {
		e0 = MakeNullEdge();
		e1 = MakeNullEdge();
		e2 = MakeNullEdge();
	}
	else {
		e0 = fold->edge[2];
		e1 = fold->edge[1];
		e2 = fold->edge[0];
	}
	e0->endpts[0] = v0; e0->endpts[1] = v1;
	e1->endpts[0] = v1; e1->endpts[1] = v2;
	e2->endpts[0] = v2; e2->endpts[1] = v0;

	tFace f = MakeNullFace();
	f->edge[0] = e0; f->edge[1] = e1; f->edge[2] = e2;
	f->vertex[0] = v0; f->vertex[1] = v1; f->vertex[2] = v2;

	e0->adjface[0] = e1->adjface[0] = e2->adjface[0] = f;

	return f;
}

void CleanEdges(void) {
	tEdge e = edges;
	do {
		if (e->newface) { 
			if (e->adjface[0]->visible)
				e->adjface[0] = e->newface; 
			else e->adjface[1] = e->newface;
			e->newface = NULL;
		}
		e = e->next;
	} while (e != edges);

	while (edges && edges->remove) { 
		e = edges;
		DELETE(edges, e);
	}
	e = edges->next;
	do {
		if (e->remove) {
			tEdge t = e;
			e = e->next;
			DELETE(edges, t);
		}
		else e = e->next;
	} while (e != edges);
}

void CleanFaces(void) {
	tFace f;
	while (faces && faces->visible) {
		f = faces;
		DELETE(faces, f);
	}
	f = faces->next;
	do {
		if (f->visible) {
			tFace t = f;
			f = f->next;
			DELETE(faces, t);
		}
		else f = f->next;
	} while (f != faces);
}

void CleanVertices(tVertex *pvnext) {
	tVertex v, t;

	tEdge e = edges;
	do {
		e->endpts[0]->onhull = e->endpts[1]->onhull = true;
		e = e->next;
	} while (e != edges);

	while (vertices && vertices->processed && !vertices->onhull) {
		if (v == *pvnext)
			*pvnext = v->next;
		v = vertices;
		DELETE(vertices, v);
	}
	v = vertices->next;
	do {
		if (v->processed && !v->onhull) {
			t = v; 
			v = v->next;
			DELETE(vertices, t)
		}
		else v = v->next;
	} while (v != vertices);

	v = vertices;
	do {
		v->duplicate = NULL;
		v->onhull = false;
		v = v->next;
	} while (v != vertices);
}

void CleanUp(tVertex *pvnext) {
	CleanEdges();
	CleanFaces();
	CleanVertices(pvnext);
}

void SubVec(double a[3], double b[3], double c[3]) {
	for (int i = 0; i < 2; ++i) c[i] = a[i] - b[i];
}

bool Collinear(tVertex a, tVertex b, tVertex c) {
	double c0 = (c->v[Z] - a->v[Z]) * (b->v[Y] - a->v[Y]) - (b->v[Z] - a->v[Z]) * (c->v[Y] - a->v[Y]);
	double c1 = (b->v[Z] - a->v[Z]) * (c->v[X] - a->v[X]) - (b->v[X] - a->v[X]) * (c->v[Z] - a->v[Z]);
	double c2 = (b->v[X] - a->v[X]) * (c->v[Y] - a->v[Y]) - (b->v[Y] - a->v[Y]) * (c->v[X] - a->v[X]);

	return c0 == 0 && c1 == 0 && c2 == 0;
}

double  Volume(tFace f, tVertex p) {
	double  ax, ay, az, bx, by, bz, cx, cy, cz, dx, dy, dz;

	ax = f->vertex[0]->v[X] - p->v[X];
	ay = f->vertex[0]->v[Y] - p->v[Y];
	az = f->vertex[0]->v[Z] - p->v[Z];
	bx = f->vertex[1]->v[X] - p->v[X];
	by = f->vertex[1]->v[Y] - p->v[Y];
	bz = f->vertex[1]->v[Z] - p->v[Z];
	cx = f->vertex[2]->v[X] - p->v[X];
	cy = f->vertex[2]->v[Y] - p->v[Y];
	cz = f->vertex[2]->v[Z] - p->v[Z];

	double vol = (ax * (by * cz - bz * cy) + ay * (bz * cx - bx * cz) + az * (bx * cy - by * cx));
	return vol;
}

void DoubleTriangle(void) {
	tVertex  v0, v1, v2, v3, t;
	tFace    f0, f1 = NULL;
	tEdge    e0, e1, e2, s;

	v0 = vertices;
	while (Collinear(v0, v0->next, v0->next->next))
		if ((v0 = v0->next) == vertices)
			printf("DoubleTriangle:  All points are Collinear!\n"), exit(0);
	v1 = v0->next;
	v2 = v1->next;

	v0->processed = true;
	v1->processed = true;
	v2->processed = true;

	f0 = MakeFace(v0, v1, v2, f1);
	f1 = MakeFace(v2, v1, v0, f0);

	f0->edge[0]->adjface[1] = f1;
	f0->edge[1]->adjface[1] = f1;
	f0->edge[2]->adjface[1] = f1;
	f1->edge[0]->adjface[1] = f0;
	f1->edge[1]->adjface[1] = f0;
	f1->edge[2]->adjface[1] = f0;

	v3 = v2->next;
	int vol = sgn(Volume(f0, v3));
	while (!vol) {
		if ((v3 = v3->next) == v0)
			printf("DoubleTriangle:  All points are coplanar!\n"), exit(0);
		vol = sgn(Volume(f0, v3));
	}
	vertices = v3;
}

void MakeCcw(tFace f, tEdge e, tVertex p) {
	tFace fv;
	tEdge s;

	if (e->adjface[0]->visible) fv = e->adjface[0];
	else fv = e->adjface[1];

	int i;
	for (i = 0; fv->vertex[i] != e->endpts[0]; ++i)
		;
	if (fv->vertex[(i + 1) % 3] != e->endpts[1]) {
		f->vertex[0] = e->endpts[1];
		f->vertex[1] = e->endpts[0];
	}
	else {
		f->vertex[0] = e->endpts[0];
		f->vertex[1] = e->endpts[1];
		swap(f->edge[1], f->edge[2]);
	}
	f->vertex[2] = p;
}

tFace MakeConeFace(tEdge e, tVertex p) {
	tEdge new_edge[2];

	for (int i = 0; i < 2; ++i)
		if (!( new_edge[i] = e->endpts[i]->duplicate)) {
			new_edge[i] = MakeNullEdge();
			new_edge[i]->endpts[0] = e->endpts[i];
			new_edge[i]->endpts[1] = p;
			e->endpts[i]->duplicate = new_edge[i];
		}

	tFace new_face = MakeNullFace();
	new_face->edge[0] = e;
	new_face->edge[1] = new_edge[0];
	new_face->edge[2] = new_edge[1];
	MakeCcw(new_face, e, p);

	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)  
			if (!new_edge[i]->adjface[j]) {
				new_edge[i]->adjface[j] = new_face;
				break;
			}
	return new_face;
}

void EdgeOrderOnFaces(void) {
	tFace f = faces;
	tEdge newEdge;
	do {
		for (int i = 0; i < 3; ++i) {
			if (!(((f->edge[i]->endpts[0] == f->vertex[i]) && (f->edge[i]->endpts[1] == f->vertex[(i + 1) % 3])) || ((f->edge[i]->endpts[1] == f->vertex[i]) &&  (f->edge[i]->endpts[0] == f->vertex[(i + 1) % 3])))) {
				for (int j = 0; j < 3; ++j) {
					if (((f->edge[j]->endpts[0] == f->vertex[i]) && (f->edge[j]->endpts[1] == f->vertex[(i + 1) % 3])) || ((f->edge[j]->endpts[1] == f->vertex[i]) && (f->edge[j]->endpts[0] == f->vertex[(i + 1) % 3]))) {
						newEdge = f->edge[i];
						f->edge[i] = f->edge[j];
						f->edge[j] = newEdge;
					}
				}
			}
		}
		f = f->next;
	} while (f != faces);
}

bool AddOne(tVertex p) {
	bool vis = false;
	tFace f = faces;
	do {
		int vol = sgn(Volume(f, p));
		if (vol < 0) {
			f->visible = true;  
			vis = true;                      
		}
		f = f->next;
	} while (f != faces);

	if (!vis) {
		p->onhull = false;
		return false;
	}

	tEdge e = edges;
	do {
		tEdge temp = e->next;
		if (e->adjface[0]->visible && e->adjface[1]->visible)
			e->remove = true;
		else if (e->adjface[0]->visible || e->adjface[1]->visible)

			e->newface = MakeConeFace(e, p);
		e = temp;
	} while (e != edges);
	return true;
}

void ConstructHull(void) {
	tVertex v = vertices;
	tVertex vnext;
	do {
		vnext = v->next;
		if (!v->processed) {
			v->processed = true;
			AddOne(v);
			CleanUp(&vnext);
		}
		v = vnext;
	} while (v != vertices);
}

double sqr(double x) {
	return x * x;
}

double dist(Vertex a, Vertex b) {
	return sqrt(sqr(a.v[X] - b.v[X]) + sqr(a.v[Y] - b.v[Y]) + sqr(a.v[Z] - b.v[Z]));
}

void Solve() {
	DoubleTriangle();
	ConstructHull();
	EdgeOrderOnFaces();
}

double FaceArea(void) {
	double totalArea = 0;
	tFace f = faces;
	do {
		Vertex p0 = *(f->vertex[0]), p1 = *(f->vertex[1]), p2 = *(f->vertex[2]);
		double a = dist(p0, p1), b = dist(p1, p2), c = dist(p2, p0);
		double p = (a + b + c) / 2;
		totalArea += sqrt(p * (p - a) * (p - b) * (p - c));
		f = f->next;
	} while (f != faces);

	return totalArea;
}

int main(void) {
	double x, y, z;
	int N;
	while (scanf("%d", &N) != EOF) {
		for (int i = 0; i < N; ++i) {
			scanf ("%lf %lf %lf", &x, &y, &z );
			tVertex v = MakeNullVertex();
			v->v[X] = x;
			v->v[Y] = y;
			v->v[Z] = z;
			v->vnum = i;
		}
		if (N <= 3) printf("0.000\n");
		else {
			Solve();
			printf("%.3lf\n", FaceArea());
		}
	}
	return 0;
}

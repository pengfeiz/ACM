#include <iostream>
using namespace std;

int a[1001]={1,1574,3562,5431,7420,9408,13250,16208,19084,23081,26058,29045,32041,35986,38962,41960,45927,48913,51902,54876,58742,61840,64817,68703,71690,74658,78532,81630,84607,87492,91570,94537,97423,104623,109352,125970,130824,137540,143280,149023,154830,160582,167302,173052,178650,184602,190452,196072,203914,208641,215480,230415,236940,241780,248501,254160,259860,265801,271540,278160,284013,289630,295470,302514,308152,314870,319602,326450,341082,347901,352740,359270,365102,370941,376580,382501,389140,394860,401823,407531,413280,419023,425830,430681,437201,452061,458760,463701,470351,476081,481902,487520,493270,501324,506931,512780,518402,524160,529860,536801,541630,548170,563012,569720,574380,581302,587031,592760,598401,605341,612083,617902,623740,629370,635102,640931,647580,652401,659130,673950,680712,685320,692170,698012,704831,710582,716302,723051,728650,734601,740351,746081,751902,758420,763280,780213,784920,791560,796301,804251,809751,815702,821540,827160,834012,839620,845370,851302,857031,862750,869401,874230,891062,895701,903641,908361,915203,920841,926570,932501,938140,943860,950712,956320,962170,968012,973620,980461,985201,1026758,1037956,1049367,1062758,1073956,1085367,1096547,1208956,1240578,1253768,1264957,1276358,1287546,1298745,1324578,1345768,1356947,1368257,1379546,1390856,1405378,1426758,1437956,1459267,1470658,1482956,1495267,1507648,
1528946,1540378,1562748,1573946,1586247,1597436,1609845,1632478,1643758,1654937,1678245,1689435,1702956,1724368,1735648,1746935,1759246,1780546,1792845,1805367,1826547,1837945,1850367,1862547,1873945,1895246,1907546,1928745,1942367,1953647,1964835,1976245,1987435,2031967,2045378,2056748,2067945,2079356,2091657,2104967,2136478,2147658,2158946,2170468,2183657,2194856,2307468,2318657,2349856,2361478,2374658,2385946,2397156,2409657,2430967,2453178,2465738,2476935,2489156,2501768,2513967,2536178,2547638,2568934,2580367,2591647,2604957,2617358,2638547,2649835,2671358,2683547,2694835,2708356,2719546,2740956,2753168,2764538,2785934,2798145,2810657,2831956,2845167,2856437,2867934,2890356,2903657,2914856,2936157,2947536,2958734,2971356,2983546,3016957,3028467,3049657,3061957,3074268,3085647,3096845,3109467,3140768,3152967,3165278,3176548,3187945,3201578,3214768,3245967,3257168,3268547,3279845,3291467,3405768,3416957,3428167,3459627,3470956,3482167,3495627,3507946,3519267,3540768,3561947,3574168,3586427,3597824,3610478,3621758,3642957,3657148,3678425,3689724,3702468,3714658,3725946,3748156,3759426,3780945,3792156,3805647,3816945,3829156,3850647,3861945,3874156,3895426,3907845,3920467,3941657,3952846,3965147,3976425,3987624,4023578,4035768,4056937,4068257,4079536,4091856,4105378,4126758,4137956,4159267,4170658,4182956,4195267,4207658,4218956,4250378,4261758,4273956,4286157,4297536,4309856,4321578,4352768,4365927,4378156,4389526,4501967,4513278,
4526738,4537926,4569137,4580637,4591836,4605278,4617538,4628935,4650278,4671538,4682935,4695137,4708536,4719835,4731268,4752638,4763925,4786135,4798325,4810956,4823167,4835627,4856923,4869135,4890536,4902856,4915267,4926537,4937825,4960257,4971536,4982735,5017368,5028647,5039846,5062378,5073648,5084936,5097246,5109647,5130967,5143278,5164738,5176934,5189246,5201768,5213967,5236178,5247638,5268934,5280367,5291647,5304967,5317268,5328647,5349826,5371268,5382647,5394826,5408267,5419637,5430967,5462178,5473628,5486923,5498136,5610748,5621947,5634178,5647328,5678923,5690247,5702648,5713946,5726148,5738426,5749823,5781246,5792436,5804936,5817246,5829436,5840936,5862147,5873426,5894723,5908246,5920647,5931846,5943167,5964327,5976823,6012478,6023758,6034957,6047258,6058437,6079834,6092357,6104758,6125947,6138257,6149537,6170945,6183257,6194537,6207945,6219357,6240758,6251947,6274158,6285437,6297834,6310478,6321758,6342957,6357148,6378425,6389724,6402378,6413758,6425937,6438157,6459327,6480935,6492157,6504738,6517934,6529147,6540738,6571934,6583147,6594327,6708934,6720358,6731548,6742935,6754138,6785324,6798523,6812357,6823547,6834925,6847135,6859324,6890734,6903257,6914537,6925834,6938145,6950437,6971834,6983145,7016548,7028945,7041368,7052648,7063945,7085246,7096435,7109845,7132468,7143658,7154936,7168245,7189435,7201956,7214368,7235648,7246935,7259146,7280546,7291845,7305268,7316548,7328945,7350268,7361548,7382945,7395146,7408536,7419835,
7431268,7452638,7463925,7486135,7498325,7510946,7523168,7534628,7546923,7569134,7590436,7602945,7614258,7625438,7638924,7650248,7681435,7692834,7805246,7816435,7829634,7841256,7852436,7863924,7895134,7908435,7920845,7932156,7943526,7954823,7968134,8012657,8023956,8035267,8046537,8057934,8071356,8092546,8104956,8126357,8137546,8149735,8162357,8173546,8194735,8207356,8219546,8240956,8253167,8264537,8275934,8297145,8310657,8321956,8345167,8356427,8367924,8390256,8402657,8413956,8426157,8437526,8459723,8471256,8492536,8504936,8517246,8529436,8540936,8562147,8573426,8594723,8609245,8620547,8631945,8643157,8654327,8675923,8701356,8712546,8723945,8735146,8746325,8759623,8791245,8903546,8914735,8926145,8937425,8950734,8962145,8973425,9016845,9028356,9041657,9052846,9064257,9075436,9086734,9120467,9132657,9143856,9156247,9167435,9178634,9203467,9214657,9235846,9247156,9258436,9270845,9283156,9305647,9316845,9328156,9350647,9361845,9374156,9385426,9407835,9420367,9431657,9452836,9465137,9476325,9487623,9512367,9523647,9534826,9547136,9568324,9580734,9603257,9614537,9625834,9638145,9650437,9671834,9683145,9705436,9716834,9730256,9741536,9752834,9764135,9785324,9807634,9821356,9832546,9843725,9856134,9867324,10235948,10263784,10289375,10347928,10375682,10425397,10459827,10487562,10537296,10573928,10623784,10649285,10685927,10735682,10763295,10798625,10847562,10875294,10934827,10962573,10987264,12057938,12085673,12345097,12369807,12397560,12457096,12483907,12530784,12569084,12596807,12645780,12683095,12709836,12758460,12795084,12843907,12870563,12908375,12956807,12984560,13054297,13079826,13208674,13267095,13294807,13450782,13479085,13507928,13564780,13592086,13629807,13678450,13706295,13752908,13790562,13829075,
13865907,13905672,13952086,13978605,14038672,14076295,14205938,14260783,14289075,14327908,14375680,14503297,14539807,14587360,14627095,14672908,14702683,14739085,14785906,14825670,14862095,14897605,14937560,14975083,15034928,15072683,15098274,15247908,15284670,15324097,15369807,15397460,15437096,15482907,15620783,15649083,15694807,15734680,15782094,15809726,15847360,15894073,15932807,15970462,16029385,16057928,16094572,16243097,16279805,16308572,16357094,16392807,16430782,16479083,16507928,16543780,16592084,16729805,16758340,16805294,16842907,16890452,16928074,16954807,17025683,17053296,17089625,17238560,17265094,17304928,17350682,17389064,17426908,17463580,17503296,17539806,17586340,17625094,17652908,17802563,17839064,17864905,17924560,17952084,17986504,18047562,18075294,18234907,18260573,18297064,18346907,
18374560,18423096,18459706,18496350,18536094,18572906,18620573,18649073,18694705,18734560,18762094,18907625,18946350,18974063,19043827,19072563,19208375,19256807,19284560,19342086,19368705,19407562,19456083,19482706,19530672,19568073,19605827,19643570,19682074,19728605,19756340,19805274,19842706,19870452,20149386,20176938,20316784,20364197,20389716,20438671,20476195,20514938,20561783,20589174,20637918,20674581,20714396,20749816,20786451,20836195,20863917,20913674,20948175,20975816,21046783,21074396,21098736,21358670,21386095,21435908,21470683,21498075,21547908,21584670,21634097,21659807,21697450,21746095,21783906,21830674,21859074,21895706,21945670,21973085,23019847,23068571,23096185,23154908,23180674,23409186,23467908,23495670,23541097,23579806,23608571,23657094,23691807,23740681,23769084,23806917,23854670,23891075,23918706,23967450,24017396,24063918,24091673,24139086,24176908,24306781,24361097,24389706,24518670,24576093,24603918,24650781,24689073,24716908,24763580,24803196,24839706,24876350,24916085,24961807,25013784,25049186,25086917,25136780,25173096,25198706,25348670,25386094,25413908,25470681,25498073,25637908,25683470,25713096,25749806,25796340,25836094,25871906,25910673,25948073,25984706,26045781,26083195,26109837,26158470,999999999};


bool judge(int w)
{
	bool d[10]={0};
	while(w)
	{
		if(d[w%10])
			return true;
		d[w%10]=true;
		w/=10;
	}
	return false;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,w,q;
	while(scanf("%d",&w),w)
	{
		i=(w-1)/1000;
		q=a[i];
		i=i*1000+1;
		for(;i<=w;i++,q++)
		{
			while(judge(q))
				q++;
		}
		q--;
		printf("%d\n",q);
	}
	return 0;
}
// ˵����Hash��������ɢ�к������ڳ�������е�Ӧ��Ŀ�� ------ ��һ������ͨ��ĳ��ת�����ƶ�Ӧ��һ��
// size_t���ͣ���unsigned long��������ֵ��
// ��Ӧ��Hash������������Ҫ�� hash��Ӧ�÷ǳ��㣩�����������
// ʵ��˵����
// ��1��������ʹ���˺��������Լ����ͼ�����ʹ�ö��������͵Ķ��󣨹ؼ��֣������á�
// ��2�������������ж�Ӧ��ƫ�ػ�������string��char*���������εȡ�
// ��3�����汾����չ��������ĳ���������������Ҫ�������ں���ʵ��ר�Ż���
// ��4��������ʵ��һ�����ͷ�ļ��У��κΰ������Ķ���ʹ��hash��������
//------------------------------------ʵ��------------------------------------------------
#include <string>
using std::string;
inline size_t hash_str( const char* s )
{
unsigned long res = 0; 
for ( ; *s; ++s )
����res = 5 * res + *s;
����return size_t(res);
����}
����template <class Key> 
����struct hash 
����{ 
����size_t operator () ( const Key& k ) const;
����};
����// һ��Ķ��󣬱��磺vector< queue<string> >�Ķ�����Ҫǿ��ת��
����template < class Key >
����size_t hash<Key>::operator () ( const Key& k ) const
����{
����size_t res = 0;
����size_t len = sizeof( Key );
����const char* p = reinterpret_cast<const char*>( &k );
����while ( len-- )
����{
����res = (res<<1)^*p++;
����}
����return res;
����}
����// ƫ�ػ�
����template<>
����size_t hash< string >::operator () ( const string& str ) const
����{
����return hash_str( str.c_str() );
����}
����typedef char* PChar;
����template<>
����size_t hash<PChar>::operator () ( const PChar& s ) const
����{
����return hash_str(s);
����}
����typedef const char* PCChar;
����template<>
����size_t hash<PCChar>::operator () ( const PCChar& s ) const
����{
����return hash_str(s);
����}
����template<> size_t hash<char>::operator () ( const char& x ) const { return x; }
����template<> size_t hash<unsigned char>::operator () ( const unsigned char& x ) const { return x; }
����template<> size_t hash<signed char>::operator () ( const signed char& x ) const { return x; }
����template<> size_t hash<short>::operator () ( const short& x ) const { return x; }
����template<> size_t hash<unsigned short>::operator () ( const unsigned short& x ) const { return x; }
����template<> size_t hash<int>::operator () ( const int& x ) const { return x; }
����template<> size_t hash<unsigned int>::operator () ( const unsigned int& x ) const { return x; }
����template<> size_t hash<long>::operator () ( const long& x ) const { return x; }
����template<> size_t hash<unsigned long>::operator () ( const unsigned long& x ) const { return x; }
����// ʹ��˵����
����// 
����// ��1����ʹ��ʱ���������Ƿ��ͣ�����Ҫ���Ϲؼ������͡�
����// 
����// ��2�������Ҫ��һ���������󣬿�����ʱ���ֲ���ȫ�ֵģ�ֻҪ��������Ϳ��ԡ�
����// 
����// ��3����Ӧ�ú������������ڶ�Ӧ���͵Ķ���
����//----------------------- hash����ʹ�þ��� -------------------------
����#include <iostream>
����#include <vector>
����#include <string>
����using namespace std;
����int main()
����{
����vector<string> vstr(2);
����vstr[0] = "sjw";
����vstr[1] = "suninf";
����hash<string> strhash; // �ֲ���������
����cout << " Hash value: " << strhash( vstr[0] ) << endl;
����cout << " Hash value: " << strhash( vstr[1] ) << endl;
����cout << " Hash value: " << hash< vector<string> >() ( vstr ) << endl;
����cout << " Hash value: " << hash<int>() ( 100 ) << endl; // hash<int>() ��ʱ��������
����return 0;
����}

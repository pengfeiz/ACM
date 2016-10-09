// 说明：Hash函数（即散列函数）在程序设计中的应用目标 ------ 把一个对象通过某种转换机制对应到一个
// size_t类型（即unsigned long）的整型值。
// 而应用Hash函数的领域主要是 hash表（应用非常广）、密码等领域。
// 实现说明：
// （1）、这里使用了函数对象以及泛型技术，使得对所有类型的对象（关键字）都适用。
// （2）、常用类型有对应的偏特化，比如string、char*、各种整形等。
// （3）、版本可扩展，如果你对某种类型有特殊的需要，可以在后面实现专门化。
// （4）、以下实现一般放在头文件中，任何包含它的都可使用hash函数对象。
//------------------------------------实现------------------------------------------------
#include <string>
using std::string;
inline size_t hash_str( const char* s )
{
unsigned long res = 0; 
for ( ; *s; ++s )
　　res = 5 * res + *s;
　　return size_t(res);
　　}
　　template <class Key> 
　　struct hash 
　　{ 
　　size_t operator () ( const Key& k ) const;
　　};
　　// 一般的对象，比如：vector< queue<string> >的对象，需要强制转化
　　template < class Key >
　　size_t hash<Key>::operator () ( const Key& k ) const
　　{
　　size_t res = 0;
　　size_t len = sizeof( Key );
　　const char* p = reinterpret_cast<const char*>( &k );
　　while ( len-- )
　　{
　　res = (res<<1)^*p++;
　　}
　　return res;
　　}
　　// 偏特化
　　template<>
　　size_t hash< string >::operator () ( const string& str ) const
　　{
　　return hash_str( str.c_str() );
　　}
　　typedef char* PChar;
　　template<>
　　size_t hash<PChar>::operator () ( const PChar& s ) const
　　{
　　return hash_str(s);
　　}
　　typedef const char* PCChar;
　　template<>
　　size_t hash<PCChar>::operator () ( const PCChar& s ) const
　　{
　　return hash_str(s);
　　}
　　template<> size_t hash<char>::operator () ( const char& x ) const { return x; }
　　template<> size_t hash<unsigned char>::operator () ( const unsigned char& x ) const { return x; }
　　template<> size_t hash<signed char>::operator () ( const signed char& x ) const { return x; }
　　template<> size_t hash<short>::operator () ( const short& x ) const { return x; }
　　template<> size_t hash<unsigned short>::operator () ( const unsigned short& x ) const { return x; }
　　template<> size_t hash<int>::operator () ( const int& x ) const { return x; }
　　template<> size_t hash<unsigned int>::operator () ( const unsigned int& x ) const { return x; }
　　template<> size_t hash<long>::operator () ( const long& x ) const { return x; }
　　template<> size_t hash<unsigned long>::operator () ( const unsigned long& x ) const { return x; }
　　// 使用说明：
　　// 
　　// （1）、使用时首先由于是泛型，所以要加上关键字类型。
　　// 
　　// （2）、其次要有一个函数对象，可以临时、局部、全局的，只要在作用域就可以。
　　// 
　　// （3）、应用函数对象作用于对应类型的对象。
　　//----------------------- hash函数使用举例 -------------------------
　　#include <iostream>
　　#include <vector>
　　#include <string>
　　using namespace std;
　　int main()
　　{
　　vector<string> vstr(2);
　　vstr[0] = "sjw";
　　vstr[1] = "suninf";
　　hash<string> strhash; // 局部函数对象
　　cout << " Hash value: " << strhash( vstr[0] ) << endl;
　　cout << " Hash value: " << strhash( vstr[1] ) << endl;
　　cout << " Hash value: " << hash< vector<string> >() ( vstr ) << endl;
　　cout << " Hash value: " << hash<int>() ( 100 ) << endl; // hash<int>() 临时函数对象
　　return 0;
　　}

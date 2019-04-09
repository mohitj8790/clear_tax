#include<bits/stdc++.h>
#include <boost/lexical_cast.hpp>
using namespace std;
using boost::lexical_cast;


template<typename C1, typename C2>
void castContainer(const C1& source, C2& destination)
{
    typedef typename C1::value_type source_type;
    typedef typename C2::value_type destination_type;
    destination.resize(source.size());
    transform(source.begin(), source.end(), destination.begin(), lexical_cast<destination_type, source_type>);
}

template<typename T, typename T2>
vector<T>& operator<<(vector<T>& v, T2 t)
{
    v.push_back(T(t));
    return v;
}

void histogram(vector<int>v,int m)
{
    sort(v.begin(),v.end());
    int n=v.size();
    auto k=v[n-1];
    int l=k/m;
    int r=m*(l+1);

    int j=1;
    int a=0;
    int b=0;
    while(j*m<=r)
    {
       int count=0;
       for(int i=0;i<n;i++)
       {
           b=a*m+1;
           if(b<=v[i] && v[i]<=j*m)
           {
              count++;
           }
           if(v[i]>j*m)
           {
              break;
           }

       }
       cout<<b<<"to"<<j*m<<":"<<" "<<count<<endl;
       j=j+1;
       a=a+1;


    }



}


int main()
{
    cout<<"enter file name"<<"\n";

    string x;
    vector<string> v1;
    char file[50];
    ifstream infile;
    cin.getline(file,50);
    infile.open(file);

    if(!infile.is_open())
    {
       cout<<"fail";
       return 0;
    }

    while(infile>>x)
    {

       v1.push_back(x);


    }
    cout<<endl;

    vector<int>v2;
    castContainer(v1, v2);
    int n2=v2.size();
    auto m=v2[n2-1];

    v2.pop_back();
    cout<<"Expected Output"<<endl;
    histogram(v2,m);

    return 0;
}

#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long

const long double eps=1e-10;
const long double PI=acos(-1.0);

typedef double T;

int sgn(T x)
{
    if(fabs(x)<eps)return 0;
    return x>0?1:-1;
}

struct PT
{
    T x,y;
    PT(){}
    PT(T _x,T _y):x(_x),y(_y){}

    PT operator+(const PT& b)const{return PT(x+b.x,y+b.y);}
    PT operator-(const PT& b)const{return PT(x-b.x,y-b.y);}
    PT operator*(const T& n)const{return PT(x*n,y*n);}
    PT operator/(const T& n)const{return PT(x/n,y/n);}
    bool operator==(const PT& b)const{return sgn(x-b.x)==0&&sgn(y-b.y)==0;}
    bool operator!=(const PT& b)const{return !(*this==b);}
    bool operator<(const PT& b)const{return (sgn(x-b.x)==0?(sgn(y-b.y)<0):(sgn(x-b.x)<0));}
};
ostream& operator<<(ostream& os,PT a){return os<<'('<<a.x<<','<<a.y<<')';}

struct Line
{
    PT s,t;
    Line(){}
    Line(PT _s,PT _t):s(_s),t(_t){}
};


T dot(PT a,PT b){return a.x*b.x+a.y*b.y;}       //点积
T cross(PT a,PT b){return a.x*b.y-a.y*b.x;}     //叉积
T vabs(PT a){return sqrt(dot(a,a));}            //模长
T dist(PT a,PT b){return vabs(a-b);}            //两点距离

PT rot(PT a,T rad)                              //逆时针旋转rad角
{
    return PT(a.x*cos(rad)-a.y*sin(rad),a.x*sin(rad)+a.y*cos(rad));
}

PT normal(PT a)                                 //逆时针的单位法向量
{
    if(vabs(a)<eps)return PT(0,0);
    return PT(-a.y,a.x)/vabs(a);
}

T angle(PT a,PT b)                              //向量夹角
{
    return abs(atan2(cross(a,b),dot(a,b)));
}

T orientedAngle(PT A,PT B,PT C)                 //定向角(逆时针)
{
    T ang=atan2(cross(B-A,C-A),dot(B-A,C-A));
    return ang+(ang<0)*2*PI;
}

T orient(PT A,PT B,PT C)                        //ABC的有向面积,逆时针为正(+)
{
    return cross(B-A,C-A)/2.0;
}

bool is_inAngle(PT A,PT B,PT C,PT p)            //判断p点是否在射线AB和AC之间(含边界)
{
    T s=sgn(orient(A,B,C));
    if(s<0)swap(B,C);
    else if(s==0)
    {
        if(sgn(dot(B-A,C-A))>0)                 //特判ABC共线，同向则p也同向才满足
        {
            return sgn(cross(B-A,p-A))==0&&sgn(dot(B-A,p-A))>=0;
        }
        else return sgn(cross(B-A,p-A))>=0;     //若反向则全满足
    }
    return sgn(orient(A,B,p))>=0&&sgn(orient(A,C,p))<=0;
}

bool is_onLine(PT p,Line l)                 //点p是否在直线ab上
{
    auto [s,t]=l;
    return sgn(cross(p-s,p-t))==0;
}
bool is_lineInter(Line l1,Line l2)          //直线l1和l2是否相交
{
    auto [s1,t1]=l1;
    auto [s2,t2]=l2;
    if(sgn(cross(t1-s1,t2-s2))==0)
    {
        if(is_onLine(s1,l2))return 1;
        return 0;
    }
    return 1;
}

bool is_onSeg(PT p,Line l)                  //点p是否在线段ab上(含端点)
{
    auto [s,t]=l;
    return sgn(cross(p-s,p-t))==0&&sgn(dot(p-s,p-t))<=0;
}
bool is_onTwoSide(PT A,PT B,Line l)         //点AB是否在直线l两侧(不包含点在直线上)
{
    auto [s,t]=l;
    return sgn(cross(A-s,t-s))*sgn(cross(B-s,t-s))<0;
}
bool is_segInter(Line l1,Line l2)           //线段l1和l2是否相交(含端点)
{
    auto [s1,t1]=l1;
    auto [s2,t2]=l2;
    if(is_onSeg(s1,l2)||is_onSeg(t1,l2)||is_onSeg(s2,l1)||is_onSeg(t2,l1))
    {
        return 1;
    }
    return is_onTwoSide(s1,t1,l2)&&is_onTwoSide(s2,t2,l1);
}

bool polar_cmp(PT a,PT b)                   //极角排序(以原点为基准)
{
    int f1=(a.y>0||a.y==0&&a.x>0)?0:1;
    int f2=(b.y>0||b.y==0&&b.x>0)?0:1;
    if(f1!=f2)return f1<f2;
    int s=sgn(cross(a,b));
    if(s!=0)return s>0;
    return dot(a,a)<dot(b,b);//这里用平方判长度
}

bool is_onRight(PT p,Line l)
{
    auto [s,t]=l;
    return sgn(cross(t-s,p-s))>=0;
}
vector<PT>getConvex(vector<PT>a)            //获得凸包
{
    if(a.size()<=2)return a;
    PT st=a[0];
    for(auto p:a)
    {
        if(p.x<st.x||p.x==st.x&&p.y<st.y)
        {
            st=p;
        }
    }
    sort(begin(a),end(a),[&](PT u,PT v)
    {
        int f1=(u.y>st.y||u.y==st.y&&u.x>st.x)?0:1;
        int f2=(v.y>st.y||v.y==st.y&&v.x>st.x)?0:1;
        if(f1!=f2)return f1<f2;
        int s=sgn(cross(u-st,v-st));
        if(s!=0)return s>0;
        return dot(u-st,u-st)<dot(u-st,v-st);//这里用平方判长度
    });
    vector<PT>ret;
    for(auto p:a)
    {
        while(ret.size()>=2&&is_onRight(p,Line(ret[ret.size()-2],ret.back())))ret.pop_back();
        ret.emplace_back(p);
    }
    return ret;
}

T RotateJam(vector<PT>&h)
{
    //h为凸包
    int n=h.size();
    if(n<=2)return 0;//只有2点的情况
    T ans=0;//初始化
    int j=2;
    for(int i=0;i<n;i++)
    {
        PT a=h[i],b=h[(i+1)%n];
        while(sgn(fabs(cross(b-a,h[(j+1)%n]-a))-fabs(cross(b-a,h[j]-a)))>=0)
        {
            j=(j+1)%n;
        }
        //处理答案
        ans;
    }
    return ans;
}

void sol()
{

}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    T = 1;
    // cin>>T;
    while (T--)sol();
}
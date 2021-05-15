#include<bits/stdc++.h>
using namespace std;
vector<int> countPoints(vector<vector<int> >& p, vector<vector<int> >& q) {
        vector<int> out;
        for(int i=0;i<q.size();i++){
            int a = q[i][0],b=q[i][2],r=q[i][2],count=0;
            for(int j=0;j<p.size();j++){
                int x = p[j][0],y=p[j][1];
                int lhs = (x-a)*(x-a) + (y-b)*(y-b);
                int rhs = r*r;
                if(lhs== rhs)
                    count++;
            }
            out.push_back(count);
        }
        return out;
    }
int main(){
	vector<vector<int> > p;
	p[0].push_back(1);
	p[0].push_back(3);
	vector<vector<int> > q;
	q[0].push_back(2);
	q[0].push_back(3);
	q[0].push_back(1);
	vector<int> v = countPoints(p,q);;
	for(int i=0;i < v.size();i++){
		cout<<v[i]<<" ";
	}
}


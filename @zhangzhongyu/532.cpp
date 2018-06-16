//Copyright (C) 2018 XiyuWang All rights reserved.
//WARNING: WHO COPY WITHOUT PERMISION WILL GET A PUNISHMENT!
#include <iostream>
#include <algorithm>
#define N 100
#define INF 10000
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int n,m,dist[N][N][2];
char f[N][N];
void dfs(int x,int y,bool life,int len){
	if(len>=dist[x][y][life]) return;
	dist[x][y][life]=len;
	if(x==n&&y==m) return;
	for(int k=0;k<4;k++){
		int nx=x+dx[k],ny=y+dy[k];
		if(nx>=1&&nx<=n&&ny>=1&&ny<=m)
			if(f[nx][ny]=='o') dfs(nx,ny,life,len+1);
			else if(life) dfs(nx,ny,0,len+1);
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>f[i][j];
	fill(dist[0][0],dist[0][0]+N*N*2,INF);
	dfs(1,1,1,0);
	int ans=min(dist[n][m][0],dist[n][m][1]);
	if(ans<INF) cout<<ans<<endl;
	else cout<<"no way"<<endl;
	return 0;
}

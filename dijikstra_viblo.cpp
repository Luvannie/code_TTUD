#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int oo = 9999999; // Đánh dấu là vô cực
typedef pair<int, int> ii;
int pre[1812];
int graph[14][14];
vector<int>path[1812]; //Lưu đường đi tới đỉnh i
vector<ii> a[1812];
int n, m;

int d[1812];

void dijkstra(int source) {
    priority_queue<ii, vector<ii>, greater<ii>> pq; //Hàng đợi ưu tiên, giá trị second bé nhất cho lên đầu
    for (int i = 1; i <= n; i++)
        d[i] = oo; //gan gia tri d[i] bang vo cuc
    d[source] = 0;
    pq.push(ii(0, source));
    while (pq.size()) {
        int u = pq.top().second; //Lấy giá trị second của phần tử đỉnh của pq
        int du = pq.top().first;
        pq.pop();
        if (du != d[u]){ //Điều kiện để bỏ qua pair mà giá trị d[u] được cập nhật từ lần lặp trước.
        	continue;
	}
        for (int i = 0; i < a[u].size(); i++) { //Xét đỉnh kề đỉnh u
            int v = a[u][i].second;
            int uv = a[u][i].first;
            if (d[v] > du + uv) { //Nếu tổng của đỉnh đang xét + trọng số của cạnh nối 2 đỉnh u và v nhỏ hơn thì cập nhật d[v] mới
            	pre[v] = u; // Đỉnh trước v là đỉnh u
                d[v] = du + uv; // Lấy giá trị nhỏ hơn
                pq.push(ii(d[v], v)); // Thêm pair vào pq
            }
        }
    }
}

int main() {
     int p, q, w, source;
    //printf("Nhap dinh nguon: ");
    scanf("%d", &source);
    //printf("Nhap so dinh: ");
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= n; j++){
    		scanf("%d", &graph[i][j]);
    		if(graph[i][j] != 0 && graph[i][j] != INT_MAX){
    			a[i].push_back(ii(graph[i][j], j));
    		}
    	}
    }
    dijkstra(source);
    for (int i = 1; i <= n; i++){
    	if(i == source) continue;
    	printf("=== Dinh %d\n", i);
    	if(d[i] == oo ){
    		printf("khong co duong di tu nguon toi dinh nay \n");
    		continue;
	}
        printf("d( %d -> %d ) = %d\n", source, i, d[i]);
	for(int tmp = i; tmp != source; tmp = pre[tmp]){
		path[i].push_back(tmp);
	}
	path[i].push_back(source);
	reverse(path[i].begin(),path[i].end());
	printf("Duong di: ");
	for(int j = 0; j < path[i].size(); j++){
		if(j == path[i].size()-1){
			printf("%d", path[i][j]);
			break;
		}
		else printf("%d -> ", path[i][j]);
	}
	printf("\n");
    }
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

struct Point{
    int x;
    int y;
};

int getOrientation(Point p, Point q, Point i){
    return(
        (q.x-p.x)*(i.y-q.y) - (q.y-p.y)*(i.x-q.x)
    );
}

vector<Point> JarvisMarch(vector<Point>&points){
    int n = points.size();
    if(n<3) return points;

    vector<Point> hull;
    int l = 0;
    for(int i=1;i<n;i++){
        if(points[i].x<points[l].x){
            l=i;
        }
    }
    int p = l;
    while(true){
        hull.push_back(points[p]);
        int q = (p+1)%n;
        for (int i=0; i<n;i++){
            if(getOrientation(points[p], points[q], points[i])>0){
                q=i;
            }
        }
        p=q;
        if(p==l)break;
    }
    return hull;
}

int main() {
    vector<Point> points = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0}, {0, 0}, {3, 3}};
    
    vector<Point> hull = JarvisMarch(points);
    
    for (int i = 0; i < hull.size(); i++) {
        cout << "(" << hull[i].x << ", " << hull[i].y << ")" << endl;
    }
    
    return 0;
}

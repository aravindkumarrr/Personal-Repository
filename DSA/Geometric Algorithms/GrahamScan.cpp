#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


struct Point{
    int x;
    int y;

    Point(int a, int b){
        x = a;
        y = b;
    }
};

int crossProd(Point a, Point b){
    int val = a.x * b.y - b.x * a.y;
    if(val > 0) return 1;
    else if(val < 0) return -1;
    else return 0;
}

int distSq(Point a, Point b){
    return(
        (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y)
    );
}

string direction(Point penultimate, Point top, Point newpoint){
    // Always for a vector u_bar from points A, B, u_bar = (B.x-A.x)i + (B.y-A.y)j
    Point u(top.x - penultimate.x, top.y - penultimate.y);
    Point v(newpoint.x-top.x, newpoint.y-top.y);

    if(crossProd(u,v)>0){
        return "CCW";
    }
    else if(crossProd(u,v)<0){
        return "CW";
    }
    else return "COLINEAR";
}

Point p0(0, 0);

bool comparePolar(const Point& p1, const Point& p2){
    string dir = direction(p0, p1, p2);
    if(dir == "COLINEAR"){
        return distSq(p0, p1) < distSq(p0, p2);
    }
    return dir == "CCW";
}

bool compare(const Point& p1, const Point& p2){
    if(p1.y!=p2.y){
        return p1.y<p2.y;
    }
    return p1.x<p2.x;
}

Point nextToTop(stack<Point>&S){
    Point top = S.top();
    S.pop();
    Point res = S.top();
    S.push(top);
    return res;
}

void grahamScan(vector<Point>&points){
    int n = points.size();
    if(n < 3) return;

    sort(points.begin(), points.end(), compare);

    p0 = points[0];

    sort(points.begin()+1, points.end(), comparePolar);

    stack<Point> s;
    s.push(p0);
    s.push(points[1]);
    s.push(points[2]);

    for(int i=3;i<n;i++){
        while(s.size()>1 && direction(nextToTop(s), s.top(), points[i])!="CCW"){
            s.pop();
        }
        s.push(points[i]);
    }

    while(!s.empty()){
        Point p = s.top();
        cout<<"("<<p.x<<", "<<p.y<<")";
        s.pop();
    }
}

int main(){
    vector<Point> points;
    int n;
    cout<<"Enter the number of Points: ";
    cin>>n;
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<"Enter points X_coordinate Y_coordinate: ";
        int x,y;
        cin>>x>>y;
        Point temp = Point(x,y);
        points.push_back(temp);
    }

    grahamScan(points);

}

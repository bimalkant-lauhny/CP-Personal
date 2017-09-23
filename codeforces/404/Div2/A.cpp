#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;
    string polyhedron;
    int faces = 0;
    while(n--) {
        cin >> polyhedron;
            if (polyhedron == "Tetrahedron") 
                faces += 4;
            else if (polyhedron == "Cube") 
                faces += 6;
            else if (polyhedron == "Octahedron") 
                faces += 8;
            else if (polyhedron == "Dodecahedron") 
                faces += 12;            
            else if (polyhedron == "Icosahedron") 
                faces += 20;
        }
    cout << faces << endl;
    return 0;
}

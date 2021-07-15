#include<iostream>
using namespace std;
class Quick_Union {
    private:
        int *size;
        int *vertices;
        int gsize;
    public:

        Quick_Union(int n) {
            gsize = n;
            vertices = new int[n];
            size = new int[n];
            for(int i=0; i < gsize; i++) {
                vertices[i] = i;
                size[i] = 1;
            }
        }

        ~Quick_Union() {
            delete [] vertices;
            delete [] size;
            gsize = 0;
        }

        int Root(int i) {
            while(i != vertices[i])
                i = vertices[i];
            return i;
        }

        void Union(int p, int q) {
            int i = Root(p); 
            int j = Root(q);

            if(i == j) return;
            if(size[j] >= size[i])
            {
                vertices[i] = j;
                size[j] += size[i];
            }
            else
            {
                vertices[j] = i;
                size[i] += size[j];
            }
        }

        void print(void) {
            for(int i=0; i < gsize; i++)
            {
                cout << "\nVertex " << i << " connected: " << vertices[i];
                cout << "\nSize: " << size[i];
            }
        }
};
int main() {
    Quick_Union q1(6);
    q1.Union(3,5);
    q1.Union(5,4);
    q1.Union(1,4);
    q1.Union(2,3);
    q1.print();
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000

int main(){
    srand(std::time(nullptr));
    string filename[] = {"Test01.txt","Test02.txt","Test03.txt","Test04.txt","Test05.txt","Test06.txt","Test07.txt","Test08.txt","Test09.txt","Test10.txt"};

    //File test 1 (tang dan)
    ofstream gene1("Test01.txt");
    vector<double> ge1;

    for(int i = 0; i < MAX; i++){
        double random_number = double(rand()) + static_cast<double>(rand()) / RAND_MAX;
        ge1.push_back(random_number);
    }

    sort(ge1.begin(), ge1.end());

    for(auto i : ge1)         
        gene1 << setprecision(4) << fixed << i <<'\n';
    
    gene1.close();
    //File test 2(giam dan)

    ofstream gene2("Test02.txt");
    vector<double> ge2;
    for(int i = 0; i < MAX; i++){
        double random_number = double(rand()) + static_cast<double>(rand()) / RAND_MAX;
        ge2.push_back(random_number);
    }

    sort(ge2.rbegin(), ge2.rend());

    for(auto i : ge2)         
        gene2 << setprecision(4) << fixed << i <<'\n';

    gene2.close();
    //File 3 to 10

    for (int i = 2; i < 10; i++){
        ofstream gene(filename[i]);
        for(int i = 0; i < MAX; i++){
            double random_number = double(rand()) + static_cast<double>(rand()) / RAND_MAX;
            gene << setprecision(4) << fixed << random_number <<'\n';
        }
        gene.close();
    }
}
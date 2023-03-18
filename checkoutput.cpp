#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000

void input(vector<double>&, string );

int main(){
    string filename[] = {"Test01.txt","Test02.txt","Test03.txt","Test04.txt","Test05.txt","Test06.txt","Test07.txt","Test08.txt","Test09.txt","Test10.txt"};
    string fileoutputquicksort[] ={"outputquicksort/OUTQUICK01.txt","outputquicksort/OUTQUICK02.txt","outputquicksort/OUTQUICK03.txt","outputquicksort/OUTQUICK04.txt","outputquicksort/OUTQUICK05.txt","outputquicksort/OUTQUICK06.txt","outputquicksort/OUTQUICK07.txt","outputquicksort/OUTQUICK08.txt","outputquicksort/OUTQUICK09.txt","outputquicksort/OUTQUICK10.txt"};
    string fileoutputmergesort[] ={"outputmergesort/OUTMERGE01.txt","outputmergesort/OUTMERGE02.txt","outputmergesort/OUTMERGE03.txt","outputmergesort/OUTMERGE04.txt","outputmergesort/OUTMERGE05.txt","outputmergesort/OUTMERGE06.txt","outputmergesort/OUTMERGE07.txt","outputmergesort/OUTMERGE08.txt","outputmergesort/OUTMERGE09.txt","outputmergesort/OUTMERGE10.txt"};
    string fileoutputheapsort[] ={"outputheapsort/OUTHEAP01.txt","outputheapsort/OUTHEAP02.txt","outputheapsort/OUTHEAP03.txt","outputheapsort/OUTHEAP04.txt","outputheapsort/OUTHEAP05.txt","outputheapsort/OUTHEAP06.txt","outputheapsort/OUTHEAP07.txt","outputheapsort/OUTHEAP08.txt","outputheapsort/OUTHEAP09.txt","outputheapsort/OUTHEAP10.txt"};
    string outtimefile[]={"QUICKSORTTIME.txt", "MERGESORTTIME.txt", "HEAPSORTTIME.txt", "SORTC++TIME.txt"};
    
    for(int i = 0; i < 10; i++){
        vector<double> stan, dayquick, dayheap, daymerge;
        input(stan, filename[i]);
        sort(stan.begin(), stan.end());
        int size = stan.size();
        input(dayquick, fileoutputquicksort[i]);
        input(dayheap, fileoutputheapsort[i]);
        input(daymerge, fileoutputmergesort[i]);
        
        for (int i = 0; i < size; i++){
            if (dayquick[i] != stan[i] || dayheap[i] != stan[i] || daymerge[i] != stan[i]){
                cout << "WRONG";
                return 0;
            }
        }
    }
    cout << "CORRECT";
}

void input(vector<double>& st , string filename){
    ifstream inp(filename);
    double x;

    for (int i = 0; i < MAX; i++){
        inp >> x;
        st.push_back(x);
    }
    inp.close();
}
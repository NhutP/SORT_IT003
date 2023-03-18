#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000

// INPUT AND OUTPUT FILE
void input(vector<double>&, string );
void output(const vector<double>&, string );

//cleaner file
void cleanfile(string);

//QUICKSORT
int partition(vector<double>&, int, int);
void QuickSort(vector<double>&, int, int);

//MERGESORT
void Merge(vector<double>&, int, int, int);
void MergeSort(vector<double>&, int, int);

//HEAPSORT
void maxheapify(vector<double>&, int i, int);
void HeapSort(vector<double>&);


int main(){
    string filename[] = {"Test01.txt","Test02.txt","Test03.txt","Test04.txt","Test05.txt","Test06.txt","Test07.txt","Test08.txt","Test09.txt","Test10.txt"};
    string fileoutputquicksort[] ={"outputquicksort/OUTQUICK01.txt","outputquicksort/OUTQUICK02.txt","outputquicksort/OUTQUICK03.txt","outputquicksort/OUTQUICK04.txt","outputquicksort/OUTQUICK05.txt","outputquicksort/OUTQUICK06.txt","outputquicksort/OUTQUICK07.txt","outputquicksort/OUTQUICK08.txt","outputquicksort/OUTQUICK09.txt","outputquicksort/OUTQUICK10.txt"};
    string fileoutputmergesort[] ={"outputmergesort/OUTMERGE01.txt","outputmergesort/OUTMERGE02.txt","outputmergesort/OUTMERGE03.txt","outputmergesort/OUTMERGE04.txt","outputmergesort/OUTMERGE05.txt","outputmergesort/OUTMERGE06.txt","outputmergesort/OUTMERGE07.txt","outputmergesort/OUTMERGE08.txt","outputmergesort/OUTMERGE09.txt","outputmergesort/OUTMERGE10.txt"};
    string fileoutputheapsort[] ={"outputheapsort/OUTHEAP01.txt","outputheapsort/OUTHEAP02.txt","outputheapsort/OUTHEAP03.txt","outputheapsort/OUTHEAP04.txt","outputheapsort/OUTHEAP05.txt","outputheapsort/OUTHEAP06.txt","outputheapsort/OUTHEAP07.txt","outputheapsort/OUTHEAP08.txt","outputheapsort/OUTHEAP09.txt","outputheapsort/OUTHEAP10.txt"};
    string fileoutputsortcpp[] ={"outputsortc++/OUTC++01.txt","outputsortc++/OUTC++02.txt","outputsortc++/OUTC++03.txt","outputsortc++/OUTC++04.txt","outputsortc++/OUTC++05.txt","outputsortc++/OUTC++06.txt","outputsortc++/OUTC++07.txt","outputsortc++/OUTC++08.txt","outputsortc++/OUTC++09.txt","outputsortc++/OUTC++10.txt"};
    string outtimefile[]={"QUICKSORTTIME.txt", "MERGESORTTIME.txt", "HEAPSORTTIME.txt", "SORTC++TIME.txt"};

    //clean file containning time 
    for (int i = 0; i < 4; i++)
        cleanfile(outtimefile[i]);

    ofstream outtimequicksort("QUICKSORTTIME.txt", ios::app);
    ofstream outtimeheapsort("HEAPSORTTIME.txt", ios::app);
    ofstream outtimemergesort("MERGESORTTIME.txt", ios::app);
    ofstream outtimesortcpp("SORTC++TIME.txt", ios::app);
    
    for (int i = 0; i < 10; i++){
        vector<double> daysortcpp;
        input(daysortcpp, filename[i]);
        vector<double> daysortquick = daysortcpp;
        vector<double> daysortheap = daysortcpp;
        vector<double> daysortmerge = daysortcpp;

        clock_t startquicksort, endquicksort;
        startquicksort = clock();
        QuickSort(daysortquick, 0, MAX - 1);
        endquicksort = clock();
        double time_takenquicksort = double(endquicksort - startquicksort) / double(CLOCKS_PER_SEC);
        output(daysortquick, fileoutputquicksort[i]);
        outtimequicksort << time_takenquicksort << '\n';

        clock_t startmergesort, endmergesort;
        startmergesort = clock();
        MergeSort(daysortmerge, 0, MAX - 1);
        endmergesort = clock();
        double time_takenmergesort = double(endmergesort - startmergesort) / double(CLOCKS_PER_SEC);
        output(daysortmerge, fileoutputmergesort[i]);
        outtimemergesort << time_takenmergesort << '\n';

        clock_t startheapsort, endheapsort;
        startheapsort = clock();
        HeapSort(daysortheap);
        endheapsort = clock();
        double time_takenheapsort= double(endheapsort - startheapsort) / double(CLOCKS_PER_SEC);
        output(daysortheap, fileoutputheapsort[i]);
        outtimeheapsort << time_takenheapsort << '\n';

        clock_t startcppsort, endcppsort;
        startcppsort = clock();
        sort(daysortcpp.begin(), daysortcpp.end());
        endcppsort = clock();
        double time_takencppsort = double(endcppsort - startcppsort) / double(CLOCKS_PER_SEC);
        output(daysortcpp, fileoutputsortcpp[i]);
        outtimesortcpp << time_takencppsort << '\n';
    }
    
}


//_________________________________________________________________________________________

//FILE INPUT AND OUTPUT

void input(vector<double>& st , string filename){
    ifstream inp(filename);
    double x;

    for (int i = 0; i < MAX; i++){
        inp >> x;
        st.push_back(x);
    }
    inp.close();
}

void output(const vector<double> &st, string filename){
    ofstream out(filename);
    for (auto i : st)
        out << setprecision(4) << fixed << i << '\n';
    out.close();
}

//clean file
void cleanfile(string filename){
    ofstream clean(filename);
    clean << "";
    clean.close();
}

//----------------------------------------------------------------
//QUICKSORT

int partition(vector<double>& st, int start, int end){
    int x = start + rand() % (end - start + 1);
    swap(st[x], st[end]);
    double pivot = st[end];
    double smallerindex = start - 1;

    for (int j = start; j < end; j++) {
        if (st[j] <= pivot) 
            swap(st[++smallerindex], st[j]);
    }
    swap(st[++smallerindex], st[end]);
    return smallerindex;
}

void QuickSort(vector<double>& st, int start, int end){
    if(start < end){
        int pi = partition(st, start, end);
        QuickSort(st, start, pi - 1);
        QuickSort(st, pi + 1, end);
    }
}

//--------------------------------------------------------------------------
//MERGESORT

void Merge(vector<double>& num, int start, int mid, int end){
    int leftnum = start;
    int rightnum = mid + 1;
    int tempindex = 0;

    vector<double> temp(end - start + 1);
    
    while(leftnum < mid + 1 && rightnum < end + 1){
        if (num[leftnum] <= num[rightnum])
            temp[tempindex++] = num[leftnum++];
        else
            temp[tempindex++] = num[rightnum++];
    }

    while(leftnum < mid + 1)
        temp[tempindex++] = num[leftnum++];

    while (rightnum < end + 1)
        temp[tempindex++] = num[rightnum++];
    
    for (int i = start; i < end + 1; i++)
        num[i] = temp[i - start];
}

void MergeSort(vector<double>& num, int left, int right){
    if (left < right){
        int mid = (left + right) / 2;
        MergeSort(num, left, mid);
        MergeSort(num,mid+1, right);
        Merge(num, left, mid, right);
    }
}

//-----------------------------------------------------------------------------------
//HEAPSORT

void maxheapify(vector<double>& num, int i, int n){
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;
    
    if (left < n && num[left] > num[largest])
        largest = left;
    
    if (right < n && num[right] > num[largest])
        largest = right;
    
    if (largest != i){
        swap(num[i], num[largest]);
        maxheapify(num, largest, n);
    }
}

void HeapSort(vector<double>& num){
    int n = num.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        maxheapify(num, i, n);
    
    for (int i = n - 1; i >= 0; i--){
        swap(num[0], num[i]);
        maxheapify(num, 0, i);
    }
}
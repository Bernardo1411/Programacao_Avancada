#include<iostream>

using namespace std;

int main(){
    int n=0, abaixo(0), acima(0);
    int *p=NULL;
    float num, media, sum=0;

    do
        {
        cout << "Insira um inteiro: " << endl;
        cin >> num;
     if(num!=0.0)
      {
        int* prov = new int[n+1];
        for(int i=0; i<n; i++)
        {
          prov[i]=p[i];
        }
        prov[n] = num;
        if(p!= NULL) delete[] p;
        p = prov;
        n++;
     }
    }while(num!=0);

    for(int i=0; i<n; i++)
    {
        sum=sum+p[i];
    }

    media = sum/n;

    for(int i=0; i<n; i++)
    {
        if(p[i]>media) acima++;
        if(p[i]<media) abaixo++;
    }

    cout << "Media: " << media << endl;
    cout << "Acima da media: " << acima << endl;
    cout << "Abaixo da media: " << abaixo << endl;

    if(p!=NULL) delete[] p;

    return 0;
}

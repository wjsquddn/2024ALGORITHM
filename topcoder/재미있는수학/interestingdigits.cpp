#include <iostream>
#include <vector>
using namespace std;
void solution(int base){
    for(int n=2;n<base;n++){
        bool ok = true;
        for(int k1=0;k1<base;k1++){
            for(int k2=0;k2<base;k2++){
                for(int k3=0;k3<base;k3++){
                    if((k1*base*base+k2*base+k3)%n==0&&(k1+k2+k3)%n!=0){
                        ok = false;
                        break;
                    }
                }
                if(!ok)break;
            }
            if(!ok)break;   
        }
        if(ok)cout<<n<<" ";
    }
}
int main(){
    int base = 3;
    solution(base);

}
# include <stdio.h>
# include <string.h>
# include <conio.h>
# include <iostream>
using namespace std;

	int key[32][16]={{0,0,1,1,1,1,0,1,0,0,1,0,1,1,1,0},
                     {1,0,1,0,1,0,0,0,1,1,0,1,1,0,0,1},
                     {0,0,0,1,1,0,0,1,0,1,1,0,1,0,0,1},
                     {1,1,1,0,1,1,0,0,1,0,1,1,0,1,1,0},
                     {0,0,1,1,1,0,0,1,1,0,1,1,0,1,0,0},
                     {0,0,0,1,1,0,1,1,0,1,1,0,1,0,1,0},
                     {0,1,0,1,0,1,0,1,1,0,0,1,0,1,0,0},
                     {0,0,1,0,1,0,0,0,1,0,1,1,0,1,1,0},
                     {1,0,1,0,1,0,1,1,1,1,1,0,0,0,1,1},
                     {0,0,0,0,1,0,1,0,0,1,1,0,1,1,1,0},
                     {1,0,1,1,1,1,0,1,0,1,1,0,1,1,1,0},
                     {1,1,0,0,1,1,0,1,1,0,0,0,1,1,0,0},
                     {0,0,0,0,0,0,1,0,1,1,0,0,1,1,0,0},
                     {1,1,1,0,0,0,1,0,1,0,0,1,0,1,1,1},
                     {1,1,0,0,0,1,0,0,1,0,1,1,0,0,1,0},
                     {1,0,0,0,0,0,1,1,1,0,0,1,1,1,0,1},
                     {0,1,0,0,1,0,0,1,0,0,1,0,1,1,0,0},
                     {0,1,1,0,0,1,0,1,0,0,0,1,1,0,1,1},
                     {1,1,0,1,0,1,0,1,1,0,1,0,0,0,0,1},
                     {0,0,0,1,1,1,0,0,0,1,0,0,1,1,1,1},
                     {1,1,0,1,0,1,0,1,1,0,1,0,1,0,0,1},
                     {0,0,1,1,0,0,1,0,0,1,0,1,0,1,0,0},
                     {1,1,0,0,0,0,1,1,0,1,0,0,0,0,1,0},
                     {1,0,0,1,1,0,0,0,0,1,0,0,1,1,0,0},
                     {1,1,1,0,1,1,0,0,0,1,0,1,1,1,1,0},
                     {1,0,0,1,1,0,0,1,0,1,0,0,0,0,0,0},
                     {1,1,0,1,1,1,1,1,0,0,1,1,0,0,1,0},
                     {1,0,1,1,0,1,1,1,0,1,1,0,0,1,0,1},
                     {0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,1},
                     {0,1,0,1,0,1,0,0,1,1,1,0,1,1,1,0},
                     {1,1,0,1,1,0,1,0,1,1,0,0,1,0,0,1},
                     {1,1,0,0,0,1,0,1,0,1,1,1,1,0,1,0}
                    };



class SLIM
{
 public:
  int keyi[32][16],
      flag = 0 ,
      out_of_Binary ,
      plain_text[32] = {1,0,1,0,
                        0,1,0,0,
                        1,0,1,0,
                        0,1,0,1,
                        0,0,1,0,
                        0,1,0,1,
                        1,0,1,0,
                        0,1,0,0,
                        },
      left[16],
      right[16],
      Out_xor_Left[16],
      permutation_arr[16],
      Out_xor_Right[16],
      out_permutation[16],
      Out_substitution[16];
  void encrypt();
  void substitution();
  void permutation();
  void xor_two_array16bit(int x[16] , int y[16] , int out_of_xor[16]);
  void Get_Binary(int arr[4]);
  void Get_array(int val , int N[4]);
  void swap_2array_16bit(int x[16] , int y[16]);
};

int main()
{
    SLIM obj1 ;
    obj1.encrypt();

    return 0;
}

void SLIM::xor_two_array16bit(int x[16] , int y[16] , int out_of_xor[16]){
    out_of_xor[0]  = x[0]  ^ y[0];
    out_of_xor[1]  = x[1]  ^ y[1];
    out_of_xor[2]  = x[2]  ^ y[2];
    out_of_xor[3]  = x[3]  ^ y[3];
    out_of_xor[4]  = x[4]  ^ y[4];
    out_of_xor[5]  = x[5]  ^ y[5];
    out_of_xor[6]  = x[6]  ^ y[6];
    out_of_xor[7]  = x[7]  ^ y[7];
    out_of_xor[8]  = x[8]  ^ y[8];
    out_of_xor[9]  = x[9]  ^ y[9];
    out_of_xor[10] = x[10] ^ y[10];
    out_of_xor[11] = x[11] ^ y[11];
    out_of_xor[12] = x[12] ^ y[12];
    out_of_xor[13] = x[13] ^ y[13];
    out_of_xor[14] = x[14] ^ y[14];
    out_of_xor[15] = x[15] ^ y[15];
}

void SLIM::substitution(){
    int out_of_substitution ;
    for(int i = 0 ; i < 4 ; i++){
        int Nible[4] = {Out_xor_Right[12-(i*4)],Out_xor_Right[13-(i*4)],
                        Out_xor_Right[14-(i*4)],Out_xor_Right[15-(i*4)]};
        Get_Binary(Nible);
        switch(out_of_Binary){
        case 0  : out_of_substitution = 12  ; break ;
        case 1  : out_of_substitution = 5  ; break;
        case 2  : out_of_substitution = 6  ; break;
        case 3  : out_of_substitution = 11 ; break;
        case 4  : out_of_substitution = 9  ; break;
        case 5  : out_of_substitution = 0 ; break;
        case 6  : out_of_substitution = 10  ; break;
        case 7  : out_of_substitution = 13 ; break;
        case 8  : out_of_substitution = 3  ; break;
        case 9  : out_of_substitution = 14 ; break;
        case 10 : out_of_substitution = 15  ; break;
        case 11 : out_of_substitution = 8  ; break;
        case 12 : out_of_substitution = 4  ; break;
        case 13 : out_of_substitution = 7  ; break;
        case 14 : out_of_substitution = 1 ; break;
        case 15 : out_of_substitution = 2 ; break;
        default : cout << "wrong value" <<endl ; break;
        }
        Get_array(out_of_substitution , Nible);
        Out_substitution[12-(i*4)] = Nible[0] ;
        Out_substitution[13-(i*4)] = Nible[1] ;
        Out_substitution[14-(i*4)] = Nible[2] ;
        Out_substitution[15-(i*4)] = Nible[3] ;
    }
}

void SLIM::Get_Binary(int arr[4]){
    /*
        convert from array 4 bit to decimal equivalent
    */
    out_of_Binary = 0 ;
    out_of_Binary |= (arr[0] << 3) | (arr[1] << 2) | (arr[2] << 1) | (arr[3] << 0);
}

void SLIM::Get_array(int val , int N[4]){
    //////////////////////// Decimal_to_Binary method //////////////////////////
         int i, temp, t , n;

        t = val;
        for (i=0; val>0 || i<4 ; i++)
        {
            if(val>0)
            {
               N[i] = val % 2;
               val /= 2;
            }
            else
            {
                for (int j=i; j<4; j++)
                N[j]=0;
            }

        }
        n = i;
        for (i=0; i < n/2; i++)
        {
            temp = N[i];
            N[i] = N[n-i-1];
            N[n-i-1] = temp;
        }
    ////////////////////////////////////////////////////////////////////////////

}

void SLIM::permutation(){
    // out_permutation & Out_substitution
    out_permutation[0] = Out_substitution[7] ;
    out_permutation[1] = Out_substitution[13] ;
    out_permutation[2] = Out_substitution[1] ;
    out_permutation[3] = Out_substitution[8] ;
    out_permutation[4] = Out_substitution[11] ;
    out_permutation[5] = Out_substitution[14] ;
    out_permutation[6] = Out_substitution[2] ;
    out_permutation[7] = Out_substitution[5] ;
    out_permutation[8] = Out_substitution[4] ;
    out_permutation[9] = Out_substitution[10] ;
    out_permutation[10] = Out_substitution[15] ;
    out_permutation[11] = Out_substitution[0] ;
    out_permutation[12] = Out_substitution[3] ;
    out_permutation[13] = Out_substitution[6] ;
    out_permutation[14] = Out_substitution[9] ;
    out_permutation[15] = Out_substitution[12] ;
}

void SLIM::swap_2array_16bit(int x[16] ,int y[16]){
    int temp[16];
    for(int i = 0 ; i < 16 ; i++){
        temp[i] = x[i] ;
    }
    for(int i = 0 ; i < 16 ; i++){
        x[i] = y[i];
    }
    for(int i = 0 ; i < 16 ; i++){
        y[i] = temp[i] ;
    }
}

void SLIM::encrypt(){

    //if(flag == 0){
        for(int i = 0 ; i < 32 ; i++){
                left[i] = plain_text[i];
                right[i] = plain_text[i + 16];
        }
     //   flag = 1 ;
    //}
    for(int i = 0 ; i < 32 ; i++){
        xor_two_array16bit(key[i] , right , Out_xor_Right);
        substitution();
        permutation();
        xor_two_array16bit(left,out_permutation ,left);
        swap_2array_16bit(left , right);
    cout<<endl;
    cout<<"/*****************************/"<<endl;
    cout<<"Round "<<(i+1)<<endl;
    cout<< "Left"<<endl;
    for(int j = 0 ; j < 16 ;){
        cout<<left[j];
        j++;
        if(j % 4 == 0){
           cout <<" | ";
        }
    }
    cout<<endl<<"right"<<endl;
        for(int j = 0 ; j < 16 ;){
        cout << right[j];
        j++;
        if(j % 4 == 0){
           cout <<" | ";
        }
    }
    }
}

# include <stdio.h>
# include <string.h>
# include <conio.h>
# include <iostream>

using namespace std;

int key[80]={
		0,0,1,1,
		1,0,0,1,
		1,0,1,1,
		0,1,0,0,
		1,1,1,0,
		1,1,0,0,
		1,0,1,1,
		0,1,1,0,
		0,0,0,1,
		1,0,0,1,
		0,1,1,0,
		1,0,0,1,
		1,0,1,0,
		1,0,0,0,
		1,1,0,1,
		1,0,0,1,
		0,0,1,1,
		1,1,0,1,
		0,0,1,0,
		1,1,1,0
		};


class data_encryption_standard{
 public:
  int flag = 0 ;
  bool Is_LSB ;
  int key_LSB[40] ,
      key_MSB[40] ,
      nible_LSB[4] ,
      nible_MSB[4] ,
      out_of_Binary,
      out_of_substitution;


  void substitution();
  void xor_two_array4bit(int x[4] , int y[4] , int out_of_xor[4]);
  void Get_Nible(int N[4] , int k[40]);
  void shift_array_4bit(int N[] , int shift_num);
  void shift_array_40bit(int N[40] , int shift_num ,int nible[4]);
  void Get_Binary(int arr[4]);
  void Get_array(int x , int N[4]);
  void key_generation();
};

int main()
{
    data_encryption_standard obj1;

    cout<<"Key inpt"<<endl;
    for (int i = 0 ; i < 80 ;){
        cout << key[i];
        i++;
        if(i % 8 == 0){
           cout <<endl;
        }
    }
    cout <<endl;
    cout <<endl;

    for(int y = 0 ; y < 110 ; ){
        obj1.key_generation();
        y++;
        if(y % 10 == 0){
            cout<<"/*******************************/"<<endl;
            cout<<"state "<<((y/10))<<endl;
            /*
            cout<<"LSB"<<endl;
            for (int i = 0 ; i < 40 ;){
                cout << obj1.key_LSB[i];
                i++;
                if(i % 4 == 0){
                   cout <<" | ";
                }
            }
            */
            cout <<endl<<"MSB"<<endl;
            for (int i = 0 ; i < 40 ;){
                cout << obj1.key_MSB[i];
                i++;
                if(i % 4 == 0){
                    cout <<" | ";
            }
            }
            cout <<endl;
        }

    }

    //cout << obj1.out_of_Binary << endl;
    return 0;
}

void data_encryption_standard::Get_Nible(int N[4] , int k[40]){
    N[3] = k[39];
    N[2] = k[38];
    N[1] = k[37];
    N[0] = k[36];
}

void data_encryption_standard::shift_array_4bit(int N[4] , int shift_num){

    for (int i = 0 ; i < shift_num ; i++)
    {
        int temp = N[3];
        N[3] = N[0];
        N[0] = N[1];
        N[1] = N[2];
        N[2] = temp;
    }
  }

void data_encryption_standard::xor_two_array4bit(int x[4] , int y[4] , int out_of_xor[4]){
    out_of_xor[0] = x[0] ^ y[0];
    out_of_xor[1] = x[1] ^ y[1];
    out_of_xor[2] = x[2] ^ y[2];
    out_of_xor[3] = x[3] ^ y[3];
}

void data_encryption_standard::Get_Binary(int arr[4]){
    /*
        convert from array 4 bit to decimal equivalent
    */
    out_of_Binary = 0 ;
    out_of_Binary |= (arr[0] << 3) | (arr[1] << 2) | (arr[2] << 1) | (arr[3] << 0);
}

void data_encryption_standard::Get_array(int val , int N[4]){
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

void data_encryption_standard::shift_array_40bit(int N[40] , int shift_num ,int nible[4]){
    /*
        shift N bit
    */
    for (int i = 0 ; i < shift_num ; i++){
        int temp = N[0];
        N[0] = N[39];
        N[39] = N[38];
        N[38] = N[37];
        N[37] = N[36];
        N[36] = N[35];
        N[35] = N[34];
        N[34] = N[33];
        N[33] = N[32];
        N[32] = N[31];
        N[31] = N[30];
        N[30] = N[29];
        N[29] = N[28];
        N[28] = N[27];
        N[27] = N[26];
        N[26] = N[25];
        N[25] = N[24];
        N[24] = N[23];
        N[23] = N[22];
        N[22] = N[21];
        N[21] = N[20];
        N[20] = N[19];
        N[19] = N[18];
        N[18] = N[17];
        N[17] = N[16];
        N[16] = N[15];
        N[15] = N[14];
        N[14] = N[13];
        N[13] = N[12];
        N[12] = N[11];
        N[11] = N[10];
        N[10] = N[9];
        N[9] = N[8];
        N[8] = N[7];
        N[7] = N[6];
        N[6] = N[5];
        N[5] = N[4];
        N[4] = N[3];
        N[3] = N[2];
        N[2] = N[1];
        N[1] = temp;
    }
    /*
        replace 4 Most bit
    */
    N[0] = nible[0];
    N[1] = nible[1];
    N[2] = nible[2];
    N[3] = nible[3];
    /*
    for (int i = 0 ; i < shift_num ; i++)
    {
        int temp = N[39];
        for(int y = 0 ; y < 39 ; y++){
            if(y == 0 ){
                N[39] = N[0];
            }
            else if(y == 39){
                N[38] = temp;
            }
            else if(y < 39){
                N[y] = N[y+1];
            }
        }
    }
    */
  }


void data_encryption_standard::substitution(){

    switch(out_of_Binary){
        case 0  : out_of_substitution = 0  ; break ;
        case 1  : out_of_substitution = 8  ; break;
        case 2  : out_of_substitution = 6  ; break;
        case 3  : out_of_substitution = 13 ; break;
        case 4  : out_of_substitution = 5  ; break;
        case 5  : out_of_substitution = 15 ; break;
        case 6  : out_of_substitution = 7  ; break;
        case 7  : out_of_substitution = 12 ; break;
        case 8  : out_of_substitution = 4  ; break;
        case 9  : out_of_substitution = 14 ; break;
        case 10 : out_of_substitution = 2  ; break;
        case 11 : out_of_substitution = 3  ; break;
        case 12 : out_of_substitution = 9  ; break;
        case 13 : out_of_substitution = 1  ; break;
        case 14 : out_of_substitution = 11 ; break;
        case 15 : out_of_substitution = 10 ; break;
        default : cout << "wrong value" <<endl ; break;
    }
    /*
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
    }*/
}

  void data_encryption_standard::key_generation(){


    /*
        divide array of key into 2 array LSB & MSB
    */
if(flag == 0){

    for(int i = 0 ; i < 40 ; i++){
            key_MSB[i] = key[i];
            key_LSB[i] = key[i + 40];
    }
            cout<<"/*******************************/"<<endl;
            cout<<"state 0"<<endl;
            cout<<"LSB"<<endl;
            for (int j = 0 ; j < 40 ;){
                cout << key_LSB[j];
                j++;
                if(j % 4 == 0){
                   cout <<" | ";
                }
            }
            cout <<endl<<"MSB"<<endl;
            for (int j = 0 ; j < 40 ;){
                cout << key_MSB[j];
                j++;
                if(j % 4 == 0){
                    cout <<" | ";
            }
            }
            cout <<endl;
    flag = 1 ;
}

    /*********************************************/

    Get_Nible(nible_LSB , key_LSB);
    shift_array_4bit(nible_LSB , 2 );
    Get_Nible(nible_MSB , key_MSB);
    xor_two_array4bit(nible_LSB , nible_MSB , nible_LSB);
    Get_Binary(nible_LSB);
    substitution();
    Get_array(out_of_substitution , nible_LSB); // convert to binary
    shift_array_4bit(nible_MSB , 3 );
    xor_two_array4bit(nible_MSB , nible_LSB , nible_MSB);
    shift_array_40bit(key_LSB , 4 , nible_LSB);
    shift_array_40bit(key_MSB , 4 , nible_MSB);

  }


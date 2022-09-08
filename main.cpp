#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>


using namespace std;
int listado();
int clientmayor(int nro);
void cantentregas(int prod);


int main()
{
    int s, t;
    s=listado();
    t=clientmayor(s);
    cantentregas(t);
    system("PAUSE");
    return 0;
}




int listado()
{
    ifstream datos, nombres;
    datos.open("Datos.txt");
    nombres.open("Nombres.txt");
    string guard, guardnom;
    float val3[200], val4[200];
    string nombguard[50], lisnomb[50];
    int val1[200], val2[200]; 
    int conmayorprod, tempc[8];
    float sumapes[8][5];
    int i=0, oo=0, u=0, j=0, x=0, d=0, e=0, tcl=0;
     
     for(u=0;u<8;u++)
     {
          for(x=0;x<5;x++)
          {  
           tempc[u]=0;                                       
          sumapes[u][x]=0;
          }
     }

     
     while (getline(datos, guard))
    {
    
         istringstream ss(guard); 
         
        
         ss >> val1[j] >> val2[j] >> val3[j] >> val4[j];
         
         switch (val1[j])
         {
         
             case 0:
                                   sumapes[0][val2[j]]=sumapes[0][val2[j]]+val3[j];
                                  break; 
                                
             case 1:        
                                   sumapes[1][val2[j]]=sumapes[1][val2[j]]+val3[j];
                                  
                    break;                        
             case 2:                    
                                   sumapes[2][val2[j]]=sumapes[2][val2[j]]+val3[j];
                                      
                    break;      
             case 3:           
                                   sumapes[3][val2[j]]=sumapes[3][val2[j]]+val3[j];
                                         
                    break;    
             case 4:
                                   sumapes[4][val2[j]]=sumapes[4][val2[j]]+val3[j];
                                      
                    break;                        
             case 5:
                                   sumapes[5][val2[j]]=sumapes[5][val2[j]]+val3[j];
                                           
                    break;                   
             case 6:         
                                   sumapes[6][val2[j]]=sumapes[6][val2[j]]+val3[j];
                                          
                    break;
             case 7:
                                   sumapes[7][val2[j]]=sumapes[7][val2[j]]+val3[j];
                                          
                    break;                            
          }
           
          j++;
          
    }
    
     
     
      d=0;
      while(getline(nombres, guardnom))
       {
                             
         nombguard[d]=guardnom;
         d++;                    
                             
       }
       j=0;
        cout<< "Listado de clientes en los productos que superan los 13000 Kg acum"<<endl;
         for(i=0;i<8;i++)
         {
                         for(oo=0;oo<5;oo++)
                         {
                                 if(sumapes[i][oo]>13000)
                                 { 
                                    
                                     if(tempc[i]==0)
                                     {
                                     lisnomb[i]=nombguard[i]+": "+nombguard[oo+8];
                                     }
                                     else lisnomb[i]=lisnomb[i]+", "+nombguard[oo+8];
                                      tempc[i]++;
                                      j++;
                                 }           
                         }                        
         }       
         
          for (e=0;e<8;e++)
          { 
                                       
          cout << lisnomb[e]<<endl;
          }
          e=0;
          cout<<endl;
          for(e=0;e<8;e++)
          {
                           if(e==0)
          
                           tcl=tempc[e];
                           else if(tempc[e]>tcl)
                           {
                                tcl=tempc[e];
                                conmayorprod=e;
                            }
                           
          }
      
         return conmayorprod;
     
} 

int clientmayor (int nro)
{
 
    ifstream datos, nombres;
    datos.open("Datos.txt");
    nombres.open("Nombres.txt");
    int tipomkm=0;
    string guard, guardnom;
    float val3[200], val4[200];
    string nombguard[50];
    int val1[200], val2[200], veccod[5]={8, 9, 10, 11, 12}; 
    int  tempc[8], tcl2=0;
    float sumakm[8][5],  tcl=0, max=500;
    int i=0, u=0, j=0, x=0, d=0, e=0;
     
     for(u=0;u<8;u++)
     {
          for(x=0;x<5;x++)
          {  
           tempc[u]=0;                                       
           sumakm[u][x]=0;
          }
     }

     
     while (getline(datos, guard))
    {
    
         istringstream ss(guard); 
         
        
         ss >> val1[j] >> val2[j] >> val3[j] >> val4[j];
         
         
         
             if(val1[j]==nro)
             sumakm[nro][val2[j]]=sumakm[nro][val2[j]]+val4[j];
                    
               
          
           
          j++;
          
          
    }
    while(getline(nombres, guardnom))
       {
                             
         nombguard[d]=guardnom;
         d++;                    
                             
       }
       j=0;
    for (i=0;i<5;i++)
    {
               for(j=0;j<4;j++)
               {
                       if(sumakm[nro][j]>sumakm[nro][j+1]) 
                       {       
                       tcl=sumakm[nro][j];
                       sumakm[nro][j]=sumakm[nro][j+1]; 
                       sumakm[nro][j+1]=tcl;
                       tcl2=veccod[j];
                        veccod[j]=veccod[j+1];
                        veccod[j+1]=tcl2;
                        
                       }
               }       
        
        
    }
    i=0;
    cout<< "Listado de Km recorridos por tipo de producto"<<endl;
    for(i=0;i<5;i++)
    {
         
         cout<< nombguard[veccod[i]]<<": "<<sumakm[nro][i]<<endl;          
         
    }   
 
     tipomkm=veccod[4]-8;
  
  return tipomkm;
    
}

void cantentregas(int prod)
{
    ifstream datos, nombres;
    datos.open("Datos.txt");
    nombres.open("Nombres.txt");
    string guard, guardnom;
    float val3[200], val4[200];
    string nombguard[50];
    int val1[200], val2[200]; 
    int  tempc[8]; 
    int i=0, u=0, j=0, x=0, d=0, e=0, contaentr=0; 
    
     while (getline(datos, guard))
    {
    
         istringstream ss(guard); 
         
        
         ss >> val1[j] >> val2[j] >> val3[j] >> val4[j];
         
         
         
             if(val2[j]==prod)
             contaentr++;
                    
               
          
           
          j++;
          
          
    }
    while(getline(nombres, guardnom))
       {
                             
         nombguard[d]=guardnom;
         d++;                    
                             
       }
       cout<<endl;
      cout<< "Cantidad de entregas para producto "<<nombguard[prod+8]<<" "<<contaentr<<endl; 
    
}    

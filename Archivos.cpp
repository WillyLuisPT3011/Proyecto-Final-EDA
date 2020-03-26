#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int clave,opcion,Bclave,nota1,nota2,sumanotas,Nnota1,Nnota2;
	char nombre[30],Nnombre[30];
	ofstream Guardar;
	ifstream Leer;
	ofstream Temp;
	Guardar.open("Fichero.txt",ios::app);
	while(true){

		cout<<"1 Guardar"<<endl;
		cout<<"2 Leer"<<endl;
		cout<<"3 Buscar"<<endl;
		cout<<"4 Eliminar"<<endl;
		cout<<"5 Modificar"<<endl;
		cout<<"Ingrese opcion"<<endl;
		cin>>opcion;

		switch(opcion){

			case 1: 
			{
				cout<<"Ingrese Nombre"<<endl;
				cin>>nombre;
				cout<<"Ingrese Clave"<<endl;
				cin>>clave;
				cout<<"Ingrese Nota 1"<<endl;
				cin>>nota1;
				cout<<"Ingrese Nota 2"<<endl;
				cin>>nota2;
				Guardar<<nombre<<" "<<clave<<" "<<nota1<<" "<<nota2<<endl;
				break;

			}
			case 2:{
				Leer.open("Fichero.txt");
				Leer>>nombre;
				while(!Leer.eof()){
					Leer>>clave>>nota1>>nota2;
					cout<<"Nombre "<<nombre<<endl;
					cout<<"Clave "<<clave<<endl;
					cout<<"Nota 1 "<<nota1<<endl;
					cout<<"Nota 2 "<<nota2<<endl;
					sumanotas=nota1+nota2;
					cout<<"Total "<<sumanotas<<endl;
					cout<<endl;
					Leer>>nombre;
				}
				Leer.close();
				break;
			}

			case 3:{
				Leer.open("Fichero.txt");
				Leer>>nombre;
				bool encontrado=false;
				cout<<"Ingrese clave a buscar"<<endl;
				cin>>Bclave;
				while(!Leer.eof()){
					Leer>>clave>>nota1>>nota2;
					if(clave==Bclave){
						encontrado=true;
						cout<<"Nombre..."<<nombre<<endl;
						cout<<"Clave...."<<clave<<endl;
						cout<<"Nota 1 "<<nota1<<endl;
						cout<<"Nota 2 "<<nota2<<endl;
						sumanotas=nota1+nota2;
						cout<<"Total "<<sumanotas<<endl;
						cout<<endl;
						
					}
					Leer>>nombre;
				}
				if(encontrado==false){
					cout<<"Clave no encontrada"<<endl;
				}
				Leer.close();
				break;


			}
			case 4:{
				Leer.open("Fichero.txt");
				Temp.open("Temp.txt");
				Leer>>nombre;
				bool encontrado=false;
				cout<<"Ingrese clave a eliminar"<<endl;
				cin>>Bclave;
				while(!Leer.eof()){
					Leer>>clave>>nota1>>nota2;
					if(clave==Bclave){
						encontrado=true;
						cout<<"Nombre..."<<nombre<<endl;
						cout<<"Clave...."<<clave<<endl;
						cout<<"Nota 1 "<<nota1<<endl;
						cout<<"Nota 2 "<<nota2<<endl;
						sumanotas=nota1+nota2;
						cout<<"Total "<<sumanotas<<endl;
						cout<<endl;
						cout<<"Eliminado"<<endl;
						
					}
					else
					{	
						Temp<<nombre<<" "<<clave<<" "<<nota1<<" "<<nota2<<endl;
					}
					Leer>>nombre;
				}
				if(encontrado==false){
					cout<<"Clave no encontrada"<<endl;
				}
				Leer.close();
				Temp.close();
				remove("Fichero.txt");
				rename("Temp.txt","Fichero.txt");
				break;

			}
			case 5:{
				Leer.open("Fichero.txt");
				Temp.open("Temp.txt");
				Leer>>nombre;
				bool encontrado=false;
				cout<<"Ingrese clave a Modificar"<<endl;
				cin>>Bclave;
				while(!Leer.eof()){
					Leer>>clave>>nota1>>nota2;
					if(clave==Bclave){
						encontrado=true;
						cout<<"Nombre..."<<nombre<<endl;
						cout<<"Clave...."<<clave<<endl;
						cout<<"Nota 1..."<<nota1<<endl;
						cout<<"Nota 2..."<<nota2<<endl;
						cout<<endl;
						cout<<"Ingrese nuevo nombre"<<endl;
						cin>>Nnombre;
						cout<<"Ingrese nueva Nota 1"<<endl;
						cin>>Nnota1;
						cout<<"Ingrese nueva Nota 2"<<endl;
						cin>>Nnota2;
						Temp<<Nnombre<<" "<<clave<<" "<<Nnota1<<" "<<Nnota2<<endl;
						cout<<"Modificado"<<endl;
						
					}
					else
					{	
						Temp<<nombre<<" "<<clave<<" "<<nota1<<" "<<nota2<<endl;
					}
					Leer>>nombre;
				}
				if(encontrado==false){
					cout<<"Clave no encontrada"<<endl;
				}
				Leer.close();
				Temp.close();
				remove("Fichero.txt");
				rename("Temp.txt","Fichero.txt");
				break;

			}


		}

	}

    return 0;
}

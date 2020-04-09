#include<stdio.h>

control::control(){
    Lis = new lista;
}
void control::controlador(){
    Lis->cargarDatos();
    menu();
    Lis->guardaDatos();
}
int control::menu(){
    int op;
    do{
     system("cls");
     cout<<"--------------------------------"<<endl;
     cout<<"------------Personas------------"<<endl;
     cout<<"--------------------------------"<<endl<<endl;
     cout<<"1). Ver"<<endl;
     cout<<"2). Agregar"<<endl;
     cout<<"3). Buscar"<<endl;
     cout<<"4). Eliminar"<<endl;
     cout<<"5). Modificar"<<endl;
     cout<<"6). Salir "<<endl;
     cout<<"Opcion ";
     cin>>op;
     if(cin.fail()){
        cin.clear();
        cin.ignore(1024, '\n');
        cout<<"Solo ingrese valores numericos"<<endl;Sleep(1000);
        op = menu();
     }
     if(op > 6 || op < 1){
        cout<<"Solo ingrese valores del 1-5 "<<endl;Sleep(1500);
        op = menu();
     }
     switch(op){
        case 1:verPersonas();break;
        case 2:agregarPersona();break;
        case 3:buscarPersona();break;
        case 4:eliminarPersona();break;
        case 5:modifica();break;
     }
    }while(op != 6);

    return op;
}
void control::verPersonas(){
    system("cls");
    cout<<Lis->toString();
    system("pause");
}
void control::agregarPersona(){
    system("cls");
    string nom, ced, ape;
    int edad;
    persona *Per;
    cout<<"Digite el nombre: ";
    cin>>nom;
    cout<<"Digite el Apellido: ";
    cin>>ape;
    cout<<"Digite la Cedula: ";
    cin>>ced;
    cout<<"Digite la Edad: ";
    cin>>edad;
    Per = Lis->personasEnLista(ced);
    if(Per == NULL){
        Lis->ingresaPersona(new persona(nom, ape, ced, edad));
    }else{
        cout<<"Ya existe persona"<<endl;Sleep(1500);
    }

}
void control::buscarPersona(){
    system("cls");
    persona *Per;
    string ced;
    cout<<"Digite la cedula: ";
    cin>>ced;
    Per = Lis->personasEnLista(ced);
    if(Per != NULL){
        system("cls");
        cout<<Per->toString()<<endl;
        system("pause");
    }else{
        cout<<"No existe esa persona"<<endl;Sleep(1500);
    }
}
void control::eliminarPersona(){
    system("cls");
    string ced;
    persona *Per;
    cout<<Lis->toString();
    cout<<"Cedula de la persona a eliminar: ";
    cin>>ced;
    Per = Lis->eliminar(ced);
    if(Per != NULL){
        delete Per;
        cout<<"***ELIMINADO OK***"<<endl;Sleep(1000);
    }else{
        cout<<"No existe persona en lista"<<endl;Sleep(1500);
    }
}
void control::modifica(){
    system("cls");
    persona *aux;
    string ced, nom;
    cout<<"Digite Cedula: ";
    cin>>ced;
    aux = Lis->personasEnLista(ced);
    if(aux != NULL){
        cout<<"Digite Nuevo Nombre: ";
        cin>>nom;
        aux->setNombre(nom);
    }else{
        cout<<"No existe persona"<<endl;Sleep(1500);
    }
}
control::~control()
{
    //dtor
}












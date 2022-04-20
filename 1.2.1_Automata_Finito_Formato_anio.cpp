#include <iostream>
#include <cctype>
using namespace std;
enum class Estado{INICIO, E1, E2, E3, E4, E5, E6, E7, E8, E9, VALIDO, INVALIDO};
bool validar (string fecha){
	int pos = 0;
	Estado actual = Estado::INICIO;
	
	while( pos < fecha.length()){
		switch(actual){
			case Estado::INICIO:
				if(isdigit(fecha[pos])){
					if(fecha[pos] == '1' || fecha[pos] == '2'){
						actual = Estado::E1;	
					}else{
						actual = Estado::INVALIDO;
					}
					
				}else{
					actual = Estado::INVALIDO;
				}
			break;
			
			case Estado::E1:
				if(isdigit(fecha[pos])){
					actual = Estado::E2;
				}else{
					actual = Estado::INVALIDO;
				}
			break;
			
			case Estado::E2:
				if(isdigit(fecha[pos])){
					actual = Estado::E3;
				}else{
					actual = Estado::INVALIDO;
				}
			break;
			
			case Estado::E3:
				if(isdigit(fecha[pos])){
					actual = Estado::E4;
				}else{
					actual = Estado::INVALIDO;
				}
			break;
			
			case Estado::E4:
				if( fecha[pos] == '/'){
					actual = Estado::E5;
				}else{
					actual = Estado::INVALIDO;
				}
			break;
			
			case Estado::E5:
				if(isdigit(fecha[pos])){
					if(fecha[pos] == '0' || fecha[pos] == '1'){
						actual = Estado::E6;	
					}else{
						actual = Estado::INVALIDO;
					}
				}else{
					actual = Estado::INVALIDO;
				}
			break;
			
			case Estado::E6:
				if(isdigit(fecha[pos])){
					if(fecha[pos-1] == '0'){
						actual = Estado::E7;	
					}else if(fecha[pos-1] == '1'){
						if(fecha[pos] == '0' || fecha[pos] == '1' || fecha[pos] == '2'){
							actual = Estado::E7;
						}else{
							actual = Estado::INVALIDO;
						}
					}else{
						actual = Estado::INVALIDO;
					}
				}else{
					actual = Estado::INVALIDO;
				}
			break;
			
			case Estado::E7:
				if( fecha[pos] == '/'){
					actual = Estado::E8;
				}else{
					actual = Estado::INVALIDO;
				}
			break;
			
			case Estado::E8:
				if(isdigit(fecha[pos])){
					if(fecha[pos] == '0' || fecha[pos] == '1' || fecha[pos] == '2' || fecha[pos] == '3'){
						actual = Estado::E9;
					}else{
						actual = Estado::INVALIDO;
					}
				}else{
					actual = Estado::INVALIDO;
				}
			break;
			
			case Estado::E9:
				if(isdigit(fecha[pos])){
					if(fecha[pos-1] == '0' || fecha[pos-1] == '1' || fecha[pos-1] == '2'){
						actual = Estado::VALIDO;	
					}else if(fecha[pos-1] == '3'){
						if(fecha[pos] == '0' || fecha[pos] == '1'){
							actual = Estado::VALIDO;
						}
					}else{
						actual = Estado::INVALIDO;
					}
				}else{
					actual = Estado::INVALIDO;
				}
			break;
			
			case Estado::VALIDO:
				actual = Estado::INVALIDO;
			break;
			
		}
		pos++;
	}	
	
	if (actual == Estado::VALIDO){
		return true;
	}else{
		return false;
	}
}
int main(){
	string date = "";
	cout<< "Ingrese la fecha: formato: AAAA/MM/DD"<<endl;
	cin>>date;
	if(validar(date)){
		cout << "True" << endl;	
	}else{
		cout << "False" <<endl;
	}
	return 0;
}

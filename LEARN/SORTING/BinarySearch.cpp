#include<bits/stdc++.h>

using namespace std;





/// BINARY SEARCH

/*


	TO SEARCH FOR AN ELEMENT IN AN ARRAY

	- ALWAYS FOR A SORTED ARRAY. Because it guides the search
	- complexity O(log n)


	

		


	







*/


void method1(int n, vector<int> array, int k){

	int left = 0, right = n-1;

	// se crean dos regiones o punteros que empiezan en el indice-->
	//0 y terminan en la ultima posicion del array.-->

	while(left <= right){

		int medium = (left + right) / 2;
		// Como el array esta ordenado se divide entre 2-->
		// y se chequean las cosas de abajo xdxdx

		if(array[medium] == k){//encontrado
			cout << k << " encontrada en indice " << medium << endl;
			break;
		}

		if(array[medium] > k){
			// quiere decir que k es mas pequena que el valor -->
			// encontrado en el indice medium. -->
			// Por tanto hay que moverse hacia la izquierda. -->
			// para eso la region de la derecha se actualiza -->
			// a medium - 1
			right = medium - 1; 
			//es medium - 1 por que en otro caso medium
			// seria la respuesta, no?
		}else{
			left = medium + 1;
		}


	}

	//cout << k << " encontrada en indice " << left << endl;



}


void method2(int n, vector<int> array, int k){

	int medium = 0;
	for(int b = n/2; b >= 1; b/=2){// empieza por la mitad del array


		// b = jump length
		// la idea es ir de izquierda a derecha y cortar al array entre
		// 2. Se crea la variable medium para poder avanzar a la derecha
		// en caso de que el numero en medium+b sea menor.

		//Idea> Hacer saltos e ir deteneindo la velocidad cuando 
		// nos acercamos. DETENER VELOCIDAD: La variacion del valor de medium




		// mientras medium + b no se pasen del indice del array
		// mientras medium+b sea menor o igual a k..
		// si al partirlo a la mitad medium + b es mayor que k -->
		// entonces b se vuelve a dividir entre 2 y la busqueda continua.
		//En caso contrario, se sabe que hay que seguir aumentando el indice del array
		//. Es decir, si el while no se cumple: r = medium ,else, l = medium 
		while(medium + b < n && array[medium+b] <= k){
			medium += b;
		}

		if(array[medium] == k){
			cout << k << " dos encontrada en indice " << medium << endl;

		}
	}




}	


void MetodosBonitos(int n, vector<int> array, int k){


	// El primer elemento del array cuyo valor sea k. Devuelve indice del array
	auto x = lower_bound(array.begin(),array.end(),k);

	//upper_bound = ultimo elemento que toma valor k
	//equal_range returns both above pointers. 
	auto y = equal_range(array.begin(),array.end(),k);
	cout << y.first << "  " << y.second << endl;

	cout << k << " tres encontrado en " << (x - array.begin()) << endl;

}


int main(){
	int n, k;
	cin >> n >> k;
	vector<int> array(n);

	for(int i = 0; i<n;i++){
		cin >> array[i];
	}

	sort(array.begin(),array.end());

	method1(n,array,k);


	method2(n,array,k);

	MetodosBonitos(n,array,k);

}

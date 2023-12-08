#include<bits/stdc++.h>

using namespace std;


void slowAlgorithm(int n ,vector<int> array){

	//a y b son los limites de un subarray y k calcula la suma de eso
	// si la suma es mas grande que lo calculado anteirormente, la variable best toma el valor de suma mas grande dedede\
	// Complejidad: O(n^3). 3 for loops e itera por cada elemento al menos 3 veces.

	int best = 0;
	for(int a = 0; a<n;a++){
		for(int b = a; b<n;b++){
			int sum = 0;
			for(int k = a; k<=b;k++){//k empieza en el lugar mas lejano y termina en b el lugar mas a la derecha de ese subarrray
				sum+=array[k];
			}
			best = max(best,sum);
		}
	}

	cout << best << " slow " << endl;


}

void mediumAlgorithm(int n,vector<int> array){

	//como se esta buscando la suma mas grande se toma el
	// subarray que empieza en a y termina en b y suma
	// los valores dados. Por cada elemento decide si
	// actulizar el valor de mejor, lo que quiere decir que
	// la sublista con suma mas larga continua o, mantenerla 
	// con lo cual empieza otra sublista. Esta nueva sublista
	// puede ser o no, mejor que la otra. 
	//COmplejidad: O(n^2) itera dos veces por la lista grande


	int best = 0;

	for(int a = 0; a<n;a++){
		int sum = 0;
		for(int b = a; b<n;b++){
			sum+=array[b];
			best = max(best,sum);
		}
	}

	cout << best << " medium "<<endl;

}

void BestAlgorithm(int n,vector<int> array){

	//viene a partir de la idea del algoritmo medium
	// por cada elemento considera si la suma de este
	// mas la suma de esa sublista, es mayor que la anterior.
	// Si la suma es mas grande eso quiere decir que la 
	// sublista con mayor suma
	// continua y a la variable best le asigna el mayor valor
	// de suma que va encontrando. Si la suma decrece best se
	// sigue manteniendo en el valor mas grande que encontro
	// de sum. La variable sum selecciona el caso que le da
	// un mejor aumento. sumar a sum el indice o que sum sea el valor del indice.


	// Se pone en un elemento 

	int best = 0;
	int sum = 0;

	for(int i = 0; i < n;i++){

		//cout << "SUM: " << array[i] << "   " << sum + array[i] << endl;

		sum = max(array[i], sum + array[i]);// para numeros enteros n, n > 0 basta con sum += array[i];
		best = max(best,sum);

	}
	cout << best << " fast " << endl;

}

struct P{
	int x,y;
	bool operator<(const P &p){
	if(x!=p.x) return x < p.x;
	else return y < p.y;
	}
};



int main(){
	int n;
	cin >> n;




	vector<int>array(n);
	for(int i = 0; i<n;i++){
		cin >> array[i];
	}

	BestAlgorithm(n,array);
	mediumAlgorithm(n,array);
	slowAlgorithm(n,array);
}
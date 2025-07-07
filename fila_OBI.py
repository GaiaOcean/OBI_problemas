#inverter o array
#edge case se o primeiro or maior que todos, retornar quantidade de alunos -1


def main() -> None:
	qtd_alunos = int(input())
	alunos_array = list()
	reversed_array = list()
	colas = 0
	last_index = 0

	for i in range(0,qtd_alunos -1): #filling up the entire array
		altura = int(input())
		alunos_array.append(altura)
	
	for i in range(0,-1,-1): #goes from -1 all the way to 0 because the array is in reverse order
		reversed_array.append(alunos_array[i]
	
	i = 1
	j = 0
	
	while i < qtd_alunos:
		if reversed_array[i] <= reversed_array[j]:	
			colas += 1
		else:
		   j = i
		i += 1
	print(colas)

if __name__ == "__main__":
	main()
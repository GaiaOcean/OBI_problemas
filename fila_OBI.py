
def main() -> None:
	qtd_alunos = int(input())
	reversed_array = list()
	colas = 0

	alunos_array = list(map(int, input().split()))  # read all heights in one line
	
	for i in range(qtd_alunos-1,-1,-1): #goes from -1 all the way to 0 because the array is in reverse order
		reversed_array.append(alunos_array[i])
	
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

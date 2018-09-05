linha = "runkffxscslvqwvtvfolwymmxprocessoslkqoifheurjzqbdlpybntwiblv"
palavra = "processos"

posicao_linha = 0
posicao_palavra = 0

comeco = -1
fim = -1

while posicao_linha < len(linha):
	if linha[posicao_linha] == palavra[posicao_palavra]:
		# print(palavra[posicao_palavra])
		if comeco < 0:
			comeco = posicao_linha
		posicao_linha += 1
		posicao_palavra += 1

	else:
		posicao_linha += 1
		posicao_palavra = 0

if comeco > 0:
	print(linha[comeco:len(palavra)])
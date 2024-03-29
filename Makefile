# Mostra os comandos
all:
	@echo "COMANDOS DISPONIVEIS:\nmake gera\nmake guloso\nmake tenta\nmake limpa\n"

# Compila e executa o algoritimo guloso
guloso:
	@gcc -c produto.c
	@gcc -c guloso.c
	@gcc -o exe produto.o guloso.o -lm
	@./exe

# Compila e executa o algoritimo de tentativa e erro
tenta:
	@gcc -c produto.c
	@gcc -c tenta-erro.c
	@gcc -o exe produto.o tenta-erro.o -lm
	@./exe

# Gera um arquivo com o numero de itens digitados aleatoriamente
gera:
	@gcc gera.c
	@./a.out

# Apaga os arquivos '.o' e o executavel, NÂO USAR SE NÃO EXISTIR ESSES ARQUIVOS
limpa:
	@rm *.o
	@rm exe

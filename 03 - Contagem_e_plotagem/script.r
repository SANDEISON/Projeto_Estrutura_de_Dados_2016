
getwd()

dados <- read.table("D:\\build-Contagem_e_plotagem\\inR.txt", col.names= c("w", "x", "y"), header= F)
#x por y
plot(c(0,40), c(0,40), type="n", xlab=("QUANTIDADE DE TESTES"), ylab="COMPARA��ES REALIZADAS A CADA TESTE")



lines(dados$w, dados$x, col="black")
lines(dados$w, dados$y, col="blue")


legend(0,40, c('Busca Binaria ', 'AVL '), col=c('black', 'blue'), pch=c(20,20,20))

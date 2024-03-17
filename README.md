# NetDiscovery v1.0

NetDiscovery é uma ferramenta de reconhecimento de rede simples e poderosa desenvolvida para ajudar na enumeração de subdomínios de um domínio-alvo e na descoberta de seus endereços IP correspondentes.

## Recursos

- Enumeração de subdomínios de um domínio-alvo.
- Descoberta dos endereços IP correspondentes aos subdomínios.
- Opção para salvar a saída em um arquivo para análises adicionais.

## Como Usar

1. **Clonar o Repositório:**

```
 git clone https://github.com/seu_usuario/NetDiscovery.git
```

2. **Compilar o Código:**

```
gcc NetDiscovery.c -o NetDiscovery
```

3. **Executar o Programa:**

```
./NetDiscovery alvo.com.br discovery.txt
```
Certifique-se de substituir alvo.com.br pelo domínio que deseja investigar e discovery.txt pelo arquivo que contém a lista de subdomínios potenciais(disponível também).


## Contribuindo

Contribuições são bem-vindas! Para contribuir com o NetDiscovery, siga estas etapas:

1. Faça um fork do projeto.
2. Crie uma nova branch (git checkout -b feature/sua_feature).
3. Faça commit das suas alterações (git commit -am 'Adicionar nova funcionalidade').
4. Faça push para a branch (git push origin feature/sua_feature).
5. Abra um Pull Request


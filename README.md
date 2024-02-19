# Jogo 2D em C com MLX42

![Exemplo de Imagem](game.png)

## Descrição
Este projeto é um jogo 2D desenvolvido em C utilizando a biblioteca gráfica MLX42 da Codam. O objetivo é controlar um personagem, coletar todos os itens no mapa e alcançar a saída(apenas aparece quando todos os itens são coletados).

## Funcionalidades
- **Personagem:** Controle de um personagem movendo-se pelo mapa(setas ou WASD).
- **Itens:** Itens espalhados no mapa para o personagem coletar.
- **Saída:** O objetivo é levar o personagem até a saída para concluir o nível.
- **Mapa:** Implementação de diversas validações.
- **Inimigo:** Inimigos espalhados para atrapalhar o player.

## Requisitos
- Linguagem: C
- Biblioteca Gráfica: MLX42 (Codam)

## Mapa
Pode-se criar qualquer mapa, desde que:
- tenha 1 coletável;
- apenas 1 saída válida;
- apenas um jogador;
- cercado por paredes;
- mapa retangular;
- sem quebras de linhas indevidas;

## Guia para criar o mapa
1 -> parede

0 -> espaço vazio

P -> jogador

E -> saída

C -> coletável

X -> inimigo(bonus)

## Versões
- Há duas versões, uma que conta apenas com os coletáveis e outra bônus, que contém inimigos e animações.

## Clone do repositório
```bash
    git@github.com:bda-mota/So_long.git
```

## Compilação e Execução
1. **Compilação versão simples:**
   ```bash
   make

   ./so_long maps/nome_do_mapa.ber
   
    exemplo: ./so_long maps/map.ber

2. **Compilação versão bonus:**
   ```bash
   make bonus

   ./so_long_bonus maps/nome_do_mapa.ber
   
   exemplo: ./so_long_bonus maps/enemy.ber

## Comandos no terminal
make clean: apaga arquivos objetos

make fclean: apaga o executável e arquivos objetos

make re: recompila o executável


# English version - 2D Game in C with MLX42

![Sample Image](game.png)

## Description
This project is a 2D game developed in C using the MLX42 graphics library from Codam. The objective is to control a character, collect all items on the map, and reach the exit (only appears when all items are collected).

## Features
- **Character:** Control a character moving around the map (using arrow keys or WASD).
- **Items:** Items scattered across the map for the character to collect.
- **Exit:** The goal is to guide the character to the exit to complete the level.
- **Map:** Implementation of various validations.
- **Enemy:** Enemies scattered to hinder the player.

## Requirements
- Language: C
- Graphics Library: MLX42 (Codam)

## Map
You can create any map, as long as it:
- has 1 collectible;
- only has 1 valid exit;
- only one player;
- surrounded by walls;
- rectangular map;
- no improper line breaks.

## Guide to Creating the Map
1 -> wall

0 -> empty space

P -> player

E -> exit

C -> collectible

X -> enemy (bonus)

## Versions
- There are two versions, one with only collectibles and another bonus version, which includes enemies and animations.

## Clone Repository
```bash
git@github.com:bda-mota/So_long.git
```

## Compilation and Execution
1. **Compilation for simple version:**
   ```bash
   make

   ./so_long maps/nome_do_mapa.ber
   
    exemplo: ./so_long maps/map.ber

2. **Compilation for bonus version**
   ```bash
   make bonus

   ./so_long_bonus maps/nome_do_mapa.ber
   
   exemplo: ./so_long_bonus maps/enemy.ber

## Terminal Commands
make clean: Deletes object files.

make fclean: Deletes the executable and object files.

make re: Recompiles the executable.


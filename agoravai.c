//Incluir as bibliotecas

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

//Inicia as variáveis globais

//cria a janela
SDL_Window *janela;

//cria a maquina que cola os adesivos na tela
SDL_Renderer *renderer;

//cria a variavel que carrega as imagens pra fazer adesivo
SDL_Surface *cortina;

SDL_Surface *fundo_preto;

SDL_Surface *circo;

SDL_Surface *vilao;

SDL_Surface *fogo;

SDL_Surface *nome_aceso;

SDL_Surface *nome_apagado;

SDL_Surface *titulo;

SDL_Surface *historia;

SDL_Surface *fundo_jogo;

SDL_Surface *plateia;

SDL_Surface *monociclo;

SDL_Surface *corda;

SDL_Surface *cadeira;

//cria a maquina que transforma as imagens em adesivo para ser colado

SDL_Texture *texture_cortina;

SDL_Texture *texture_fundo_preto;

SDL_Texture *texture_circo;

SDL_Texture *texture_vilao;

SDL_Texture *texture_fogo;

SDL_Texture *texture_nome_aceso;

SDL_Texture *texture_nome_apagado;

SDL_Texture *texture_titulo;

SDL_Texture *texture_historia;

SDL_Texture *texture_fundo_jogo;

SDL_Texture *texture_plateia;

SDL_Texture *texture_monociclo;

SDL_Texture *texture_corda;

SDL_Texture *texture_cadeira;

//cria as variaveis de corte e de colagem dos adesivos na tela do jogo

SDL_Rect corte_img_cortina;

SDL_Rect tamanho_img_cortina;

SDL_Rect corte_img_cortina1;

SDL_Rect tamanho_img_cortina1;

SDL_Rect corte_img_fundo;

SDL_Rect tamanho_img_fundo;

SDL_Rect corte_img_circo;

SDL_Rect tamanho_img_circo;

SDL_Rect corte_img_vilao;

SDL_Rect tamanho_img_vilao;

SDL_Rect corte_img_fogo;

SDL_Rect tamanho_img_fogo;

SDL_Rect corte_img_nomeac;

SDL_Rect tamanho_img_nomeac;

SDL_Rect corte_img_nomeap;

SDL_Rect tamanho_img_nomeap;

SDL_Rect corte_img_titulo;

SDL_Rect tamanho_img_titulo;

SDL_Rect corte_img_titulo1;

SDL_Rect tamanho_img_titulo1;

SDL_Rect corte_img_historia;

SDL_Rect tamanho_img_historia;

SDL_Rect corte_img_funjogo;

SDL_Rect tamanho_img_funjogo;

SDL_Rect corte_img_funjogo1;

SDL_Rect tamanho_img_funjogo1;

SDL_Rect corte_img_plateia;

SDL_Rect tamanho_img_plateia;

SDL_Rect corte_img_plateia1;

SDL_Rect tamanho_img_plateia1;

SDL_Rect corte_img_monociclo;

SDL_Rect tamanho_img_monociclo;

SDL_Rect corte_img_corda;

SDL_Rect tamanho_img_corda;

SDL_Rect corte_img_corda1;

SDL_Rect tamanho_img_corda1;

SDL_Rect corte_img_cadeira;

SDL_Rect tamanho_img_cadeira;

double contador_velocidade = 0.0;

int velocidade = 0;

int andar = 0;

int arremesso = 0;

int contador;

int up;

int jogo(int parada)
{
	parada = 3;
	while(parada ==3)
	{
		SDL_Event event;
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_QUIT:
					parada = 10;					
					SDL_DestroyRenderer(renderer);
					return 0;
					break;
				case SDL_KEYDOWN:
					switch(event.key.keysym.scancode)
					{
						case SDL_SCANCODE_RETURN:
						case SDL_SCANCODE_KP_5:
							andar = 1;
							break;
						case SDL_SCANCODE_UP:
						case SDL_SCANCODE_KP_8:
							up = 1;
							break;
					}	
			}
		}
		contador_velocidade += 0.5;
		if (contador_velocidade >= 1.0)
		{
			velocidade++;
			contador_velocidade = 0.0;
		}

		if (andar == 1)
		{
			tamanho_img_funjogo.y += 5 + velocidade;
			tamanho_img_funjogo1.y += 5 + velocidade;

			tamanho_img_plateia.y += 5 + velocidade;
			tamanho_img_plateia1.y += 5 + velocidade;

			tamanho_img_corda.y += 5 + velocidade;
			tamanho_img_corda1.y += 5 + velocidade;


			corte_img_monociclo.x += 26;
			if (corte_img_monociclo.x >= 104)
			{
				corte_img_monociclo.x = 0;
			}

			if (velocidade%7==0)
			{
				arremesso = 1;
			}
			if (arremesso==1)
			{
				tamanho_img_cadeira.x += 30;
				tamanho_img_cadeira.y = tamanho_img_cadeira.x + 30;
				tamanho_img_cadeira.w = 100;
				tamanho_img_cadeira.h = 40;
				if (tamanho_img_cadeira.y >= 480)
				{
					arremesso = 0;
					tamanho_img_cadeira.x = 0;
					tamanho_img_cadeira.y = 0;
					tamanho_img_cadeira.w = 0;
					tamanho_img_cadeira.h = 0;
				}
			}

			if (tamanho_img_corda.y >= 480)
			{
				tamanho_img_corda.y = tamanho_img_corda1.y - 480;
			}

			if (tamanho_img_corda1.y >= 480)
			{
				tamanho_img_corda1.y = tamanho_img_corda.y - 480;
			}

			if (tamanho_img_funjogo.y >= 480)
			{
				tamanho_img_funjogo.y = tamanho_img_funjogo1.y - 480;
			}
			
			if (tamanho_img_plateia1.y >= 480)
			{
				tamanho_img_plateia1.y = tamanho_img_plateia.y - 490;
			}

			if (tamanho_img_funjogo1.y >= 480)
			{
				tamanho_img_funjogo1.y = tamanho_img_funjogo.y - 480;
			}
			
			if (tamanho_img_plateia.y >= 480)
			{
				tamanho_img_plateia.y = tamanho_img_plateia1.y - 490;
			}	
		}

		if (tamanho_img_cadeira.x == tamanho_img_monociclo.x)
		{
			return 0;
		}		

		if (up == 1)
		{
			tamanho_img_monociclo.y -= 10;
			tamanho_img_monociclo.x -= 5;
			tamanho_img_monociclo.w += 10;
			tamanho_img_monociclo.h += 10;

			if (tamanho_img_monociclo.y <= 200)
			{
				up = 2;
			}
		}
		if (up == 2)
		{
			tamanho_img_monociclo.y += 10;
			tamanho_img_monociclo.x += 5;
			tamanho_img_monociclo.w -= 10;
			tamanho_img_monociclo.h -= 10;
			
			if (tamanho_img_monociclo.y >= 250)
			{
				tamanho_img_monociclo.y = 250;
				up = 0;
			}
		}
		

		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, texture_fundo_jogo, &corte_img_funjogo, &tamanho_img_funjogo);
		SDL_RenderCopy(renderer, texture_fundo_jogo, &corte_img_funjogo1, &tamanho_img_funjogo1);
		SDL_RenderCopy(renderer, texture_plateia, &corte_img_plateia, &tamanho_img_plateia);
		SDL_RenderCopy(renderer, texture_plateia, &corte_img_plateia1, &tamanho_img_plateia1);
		SDL_RenderCopy(renderer, texture_corda, &corte_img_corda, &tamanho_img_corda);
		SDL_RenderCopy(renderer, texture_corda, &corte_img_corda1, &tamanho_img_corda1);
		SDL_RenderCopy(renderer, texture_cadeira, &corte_img_cadeira, &tamanho_img_cadeira);
		SDL_RenderCopy(renderer, texture_monociclo, &corte_img_monociclo, &tamanho_img_monociclo);
		SDL_RenderPresent(renderer);

		SDL_Delay(1000/10);
	}
	return 0;
}

void sinopse()
{
	int parada = 0;
	while (parada == 0)
	{
		SDL_Event event;
		while(SDL_PollEvent(&event))
		{
			switch (event.type)
            {
            	case SDL_QUIT:
                	parada = 10;
                	return;               
                	break;
            	case SDL_KEYDOWN:
            		return;
            		break;
            }
            SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer, texture_historia, &corte_img_historia, &tamanho_img_historia);
            SDL_RenderPresent(renderer);
		}
	}
	return;
}

int menu(int parada)
{	
	parada = 2;
	int seletor = 0;
	while( parada == 2)
	{
		SDL_Event event;
        while (SDL_PollEvent(&event))
        {   
            switch (event.type)
            {
            	case SDL_QUIT:
                	parada = 10;
                	SDL_DestroyRenderer(renderer);
                	SDL_DestroyWindow(janela);
                	SDL_Quit();
                	break;
            	case SDL_KEYDOWN:
                	switch (event.key.keysym.scancode)
                	{
                		case SDL_SCANCODE_DOWN:
                 	  		seletor++;
                  	  		if(seletor > 4) seletor = 0;
                  	  		break;
                		case SDL_SCANCODE_UP:
                  	  		seletor--;
                  	  		if(seletor<0) seletor = 4;
                  	  		break;
                		case SDL_SCANCODE_RETURN:
                  	  		switch(seletor)
                    		{
                        		case 0://historia do jogo
                            		sinopse();
                            		break;
                        		case 1://iniciar o jogo
                            		jogo(parada);
                            		break;
                            }
                        		/*case 2://ranking
                            		ranking();
                            		break;
                        		case 3://creditos
                            		creditos();
                            		break;
                    		}*/
                    		break;

                	}
                	break;
                
            }
        }
        switch(seletor)
        {
        case 0://iniciar jogo     
        	tamanho_img_titulo1.y = 35;
        	tamanho_img_titulo1.h = 90;
        	corte_img_titulo1.y = 0;
        	corte_img_titulo1.h = 100;
            break;
        case 1://como jogar
        	tamanho_img_titulo1.y = 126;  
        	tamanho_img_titulo1.h = 65;   
        	corte_img_titulo1.y = 105;
        	corte_img_titulo1.h = 80;     
            break;
        case 2://ranking
        	tamanho_img_titulo1.y = 198;  
        	tamanho_img_titulo1.h = 65;   
        	corte_img_titulo1.y = 190;
        	corte_img_titulo1.h = 80;    
            break;
        case 3://creditos
        	tamanho_img_titulo1.y = 268;  
        	tamanho_img_titulo1.h = 65;   
        	corte_img_titulo1.y = 275;
        	corte_img_titulo1.h = 80;     
            break;
        case 4:
			tamanho_img_titulo1.y = 338;  
        	tamanho_img_titulo1.h = 65;   
        	corte_img_titulo1.y = 360;
        	corte_img_titulo1.h = 80;
        	break;
        }
        
        


        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture_cortina, &corte_img_cortina, &tamanho_img_cortina);
		SDL_RenderCopy(renderer, texture_cortina, &corte_img_cortina1, &tamanho_img_cortina1);
		SDL_RenderCopy(renderer, texture_titulo, &corte_img_titulo, &tamanho_img_titulo);
		SDL_RenderCopy(renderer, texture_titulo, &corte_img_titulo1, &tamanho_img_titulo1);
		SDL_RenderPresent(renderer);
		SDL_Delay(1000/10);

	}
	return 0;
}

int abertura(int parada)
{	
	parada = 1;
	int down = 0;
    while(parada == 1){
            SDL_Event event;
        while (SDL_PollEvent(&event)){   
            switch (event.type)
            {
            case SDL_QUIT:
            	parada = 10;
                SDL_DestroyRenderer(renderer);
                SDL_DestroyWindow(janela);
                SDL_Quit();
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.scancode)
                {
                case SDL_SCANCODE_RETURN:
                    down +=1;
                    break;
                }
                break;
            }
        }
        if (down == 0)
        {
        	contador ++;
        	tamanho_img_cortina.x -= 10;
			tamanho_img_cortina1.x += 10;

			corte_img_fogo.x += 400;

			if (tamanho_img_cortina.x <= -340 && tamanho_img_cortina1.x >= 660)
			{
				tamanho_img_cortina.x = -320;
				tamanho_img_cortina1.x = 640;
			}
			if (corte_img_fogo.x >= 3200)
	    	{
	    		corte_img_fogo.x = 0;
	    	}
	    	
	    	if (contador >= 5 && contador <= 8)
        	{
				tamanho_img_nomeap.w = 500;
				tamanho_img_nomeap.h = 260;
       		}
       		else 
       		{
       			tamanho_img_nomeap.w = 0;
				tamanho_img_nomeap.h = 0;
				if (contador >= 13)
				{
					contador = 0;
				}
       		}
        }
        if (down == 1)
        {
        	tamanho_img_cortina.x += 10;
			tamanho_img_cortina1.x -= 10;
			if (tamanho_img_cortina.x >= 0 && tamanho_img_cortina1.x <= 320)
			{
				tamanho_img_cortina.x = 0; 
				tamanho_img_cortina1.x = 320;
				menu(parada);
				return 0;
			}
        }
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture_fogo, &corte_img_fogo, &tamanho_img_fogo);
		SDL_RenderCopy(renderer, texture_circo, &corte_img_circo, &tamanho_img_circo);
        SDL_RenderCopy(renderer, texture_vilao, &corte_img_vilao, &tamanho_img_vilao);
        SDL_RenderCopy(renderer, texture_nome_aceso, &corte_img_nomeac, &tamanho_img_nomeac);
        SDL_RenderCopy(renderer, texture_nome_apagado, &corte_img_nomeap, &tamanho_img_nomeap);
        SDL_RenderCopy(renderer, texture_cortina, &corte_img_cortina, &tamanho_img_cortina);
		SDL_RenderCopy(renderer, texture_cortina, &corte_img_cortina1, &tamanho_img_cortina1);
		SDL_RenderPresent(renderer);
		SDL_Delay(1000/10);
    }
    return 0;
}	

int main(void)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	janela = SDL_CreateWindow("Diverbras", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
	renderer = SDL_CreateRenderer(janela, -1, 0);

	cortina = IMG_Load("Cortina.png");
	fundo_preto = IMG_Load("FundoPreto.png");
	circo = IMG_Load("Circo.png");
	vilao = IMG_Load("Vilao.png");
	fogo = IMG_Load("Fogo.png");
	nome_aceso = IMG_Load("NomeLuz.png");
	nome_apagado = IMG_Load("NomeApagado.png");
	titulo = IMG_Load("Titulo.png");
	historia = IMG_Load("Historia.png");
	fundo_jogo = IMG_Load("FundoJogo.png");
	plateia = IMG_Load("Torcida.png");
	monociclo = IMG_Load("Monociclo.png");
	corda = IMG_Load("Corda.png");
	cadeira = IMG_Load("Cadeira.png");

	texture_cortina = SDL_CreateTextureFromSurface(renderer, cortina);
	texture_fundo_preto = SDL_CreateTextureFromSurface(renderer, fundo_preto);
	texture_circo = SDL_CreateTextureFromSurface(renderer, circo);
	texture_vilao = SDL_CreateTextureFromSurface(renderer, vilao);
	texture_fogo = SDL_CreateTextureFromSurface(renderer, fogo);
	texture_nome_aceso = SDL_CreateTextureFromSurface(renderer, nome_aceso);
	texture_nome_apagado = SDL_CreateTextureFromSurface(renderer, nome_apagado);
	texture_titulo = SDL_CreateTextureFromSurface(renderer, titulo);
	texture_historia = SDL_CreateTextureFromSurface(renderer, historia);
	texture_fundo_jogo = SDL_CreateTextureFromSurface(renderer, fundo_jogo);
	texture_plateia = SDL_CreateTextureFromSurface(renderer, plateia);
	texture_monociclo = SDL_CreateTextureFromSurface(renderer, monociclo);
	texture_corda = SDL_CreateTextureFromSurface(renderer, corda);
	texture_cadeira = SDL_CreateTextureFromSurface(renderer, cadeira);

	corte_img_cortina.x = 0;
	corte_img_cortina.y	= 0;
	corte_img_cortina.w = 920/2;
	corte_img_cortina.h = 765;

	tamanho_img_cortina.x = 0;
	tamanho_img_cortina.y = 0;
	tamanho_img_cortina.w = 640/2;
	tamanho_img_cortina.h = 480;

	corte_img_cortina1.x = 920/2;
	corte_img_cortina1.y = 0;
	corte_img_cortina1.w = 920/2;
	corte_img_cortina1.h = 765;

	tamanho_img_cortina1.x = 640/2;
	tamanho_img_cortina1.y = 0;
	tamanho_img_cortina1.w = 640/2;
	tamanho_img_cortina1.h = 480;

	corte_img_circo.x = 0;
	corte_img_circo.y = 0;
	corte_img_circo.w = 640;
	corte_img_circo.h = 480;

	tamanho_img_circo.x = 140;
	tamanho_img_circo.y = 120;
	tamanho_img_circo.w = 370;
	tamanho_img_circo.h = 230;

	corte_img_vilao.x = 0;
	corte_img_vilao.y = 0;
	corte_img_vilao.w = 1000;
	corte_img_vilao.h = 1000;

	tamanho_img_vilao.x = 140;
	tamanho_img_vilao.y = -45;
	tamanho_img_vilao.w = 360;
	tamanho_img_vilao.h = 280;

	corte_img_fogo.x = 0;
	corte_img_fogo.y = 0;
	corte_img_fogo.w = 400;
	corte_img_fogo.h = 500;

	tamanho_img_fogo.x = 0;
	tamanho_img_fogo.y = 0;
	tamanho_img_fogo.w = 640;
	tamanho_img_fogo.h = 480;

	corte_img_nomeac.x = 150;
	corte_img_nomeac.y = 100;
	corte_img_nomeac.w = 600;
	corte_img_nomeac.h = 380;

	tamanho_img_nomeac.x = 120;
	tamanho_img_nomeac.y = 260;
	tamanho_img_nomeac.w = 500;
	tamanho_img_nomeac.h = 260;

	corte_img_nomeap.x = 150;
	corte_img_nomeap.y = 100;
	corte_img_nomeap.w = 600;
	corte_img_nomeap.h = 380;

	tamanho_img_nomeap.x = 120;
	tamanho_img_nomeap.y = 260;
	tamanho_img_nomeap.w = 0;
	tamanho_img_nomeap.h = 0;

	corte_img_titulo.x = 320; 
	corte_img_titulo.y = 0;
	corte_img_titulo.w = 320;
	corte_img_titulo.h = 480;

	tamanho_img_titulo.x = 195;
	tamanho_img_titulo.y = 40;
	tamanho_img_titulo.w = 340;
	tamanho_img_titulo.h = 400;

	corte_img_titulo1.x = 50; 
	corte_img_titulo1.y = 0;
	corte_img_titulo1.w = 260;
	corte_img_titulo1.h = 100;

	tamanho_img_titulo1.x = 195;
	tamanho_img_titulo1.y = 35;
	tamanho_img_titulo1.w = 275;
	tamanho_img_titulo1.h = 90;

	corte_img_historia.x = 0;
	corte_img_historia.y = 0;
	corte_img_historia.w = 1024;
	corte_img_historia.h = 684;
	
	tamanho_img_historia.x = 0;
	tamanho_img_historia.y = 0;
	tamanho_img_historia.w = 640;
	tamanho_img_historia.h = 480;

	corte_img_funjogo.x = 0;
	corte_img_funjogo.y = 0;
	corte_img_funjogo.w = 640;
	corte_img_funjogo.h = 480;
	
	tamanho_img_funjogo.x = 0;
	tamanho_img_funjogo.y = 10;
	tamanho_img_funjogo.w = 640;
	tamanho_img_funjogo.h = 480;

	corte_img_funjogo1.x = 0;
	corte_img_funjogo1.y = 0;
	corte_img_funjogo1.w = 640;
	corte_img_funjogo1.h = 480;
	
	tamanho_img_funjogo1.x = 0;
	tamanho_img_funjogo1.y = -480;
	tamanho_img_funjogo1.w = 640;
	tamanho_img_funjogo1.h = 480;

	corte_img_plateia.x = 0;
	corte_img_plateia.y = 0;
	corte_img_plateia.w = 640;
	corte_img_plateia.h = 480;
	
	tamanho_img_plateia.x = 0;
	tamanho_img_plateia.y = 10;
	tamanho_img_plateia.w = 640;
	tamanho_img_plateia.h = 480;

	corte_img_plateia1.x = 0;
	corte_img_plateia1.y = 0;
	corte_img_plateia1.w = 640;
	corte_img_plateia1.h = 480;

	tamanho_img_plateia1.x = 0;
	tamanho_img_plateia1.y = -480;
	tamanho_img_plateia1.w = 640;
	tamanho_img_plateia1.h = 480;

	corte_img_monociclo.x = 0;
	corte_img_monociclo.y = 0;
	corte_img_monociclo.w = 25;
	corte_img_monociclo.h = 50;

	tamanho_img_monociclo.x = 300; 
	tamanho_img_monociclo.y = 250;
	tamanho_img_monociclo.w = 50;
	tamanho_img_monociclo.h = 100;

	corte_img_corda.x = 0;
	corte_img_corda.y = 0;
	corte_img_corda.w = 640;
	corte_img_corda.h = 480;

	tamanho_img_corda.x = 85;
	tamanho_img_corda.y = 0;
	tamanho_img_corda.w = 480;
	tamanho_img_corda.h = 480;

	corte_img_corda1.x = 0;
	corte_img_corda1.y = 0;
	corte_img_corda1.w = 640;
	corte_img_corda1.h = 480;

	tamanho_img_corda1.x = 85;
	tamanho_img_corda1.y = -480;
	tamanho_img_corda1.w = 480;
	tamanho_img_corda1.h = 480;

	corte_img_cadeira.x = 40;
	corte_img_cadeira.y = 0;
	corte_img_cadeira.w = 640;
	corte_img_cadeira.h = 440;
	
	tamanho_img_cadeira.x = 0;
	tamanho_img_cadeira.y = 0;
	tamanho_img_cadeira.w = 0;
	tamanho_img_cadeira.h = 0;


	int parada = 0;
	
	if(parada == 0)
	{
		abertura(parada);
	}
	return 0;
}




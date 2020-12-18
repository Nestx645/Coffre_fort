/*
     **********************************************************************************
    |                                                                                  |
    |                                                        ###      ########         |
    |    encodeur.c                                        ###      ###    ###         |
    |                                                    ### ###         ###           |
    |    Made by Nesta                                 ###  ###       ###              |
    |                                                ###########   ###                 |
    |                                                     ###    ###                   |
    |    Created: 2020/12/18 1:37 by Nesta              ###   ########                |
    |                                                                                  |
     **********************************************************************************
*/


#include<stdio.h>
#include<stdlib.h>
#include <string.h>


int main ()
{

    // Declaration des variables

    char *message;
    int i;
    int nbr;
    char request;
    int key;
    int current_letter;
    char mdp[5];

    // ------------------------------------------------------------------------------
    // Demande d'action 
    
    printf("\nVoulez vous vous conecter(c) ou encoder/decoder(e ou d) un message ? ");
    scanf("%c", &request);

    if (request == 'c')
    {
        goto connected;
    }
    else if (request == 'e' || request == 'd')
    {
        goto edit;
    }else
    {
        printf("demande non corecte !");
        goto end;
    }
    
    
    // ------------------------------------------------------------------------------
    // Code pour le decodage / l'encodage

    edit:
    
    printf("\n\nEntrer la cle : ");
    scanf("%d",&key);

    printf("Le message chiffre est: ");
    scanf("%s",message);
 
    printf("%s est devenu ", message);
    for(i = 0; i <= strlen(message); i++)
    {
        printf("%c", message[i]+key);
    }
    printf(" avec la cle de chiffrement %d \n\n", key);

    goto end;
    // ------------------------------------------------------------------------------
    // Code pour se connecter à ses mdp

    connected:

    printf("Entrer la cle  : ");
    scanf("%d",&key);

    printf("Le message chiffre est : ");
    scanf("%s",message);
 
    for(i = 0; i <= strlen(message); i++)
    {
        printf("%c",message[i]+key);
        current_letter = message[i]+key;
        mdp[i] = current_letter;
    }

    // ------------------------------------------------------------------------------
    // Verification du mdp caractère par caratère
    // Ici le mot de passe sera TUVWX  avec la clé 13 --> (abcde)
    if (mdp[0] == 97 && mdp[1] == 98 && mdp[2] == 99 && mdp[3] == 100 && mdp[4] == 101 && key == 13)
    {
        printf("\n\nVos mots de passe : ");
        printf("\n- Compte Twitch  : abcdee");
        printf("\n- Compte Spotify  : abcdeee");
    }else 
    {
        printf("\n\nAcces refuse");
    }
    end:

    printf("\n");
    return(0);
}


















// int encode(char lettre);

// int main(int argc, char** argv)
// {
//     printf("Mot a coder : ");
//     char* MotACoder;
//     scanf("%s", &MotACoder);

//     // Toutes les lettres du Mot à Coder
    
//     printf("Le mot %s a ete encoder et est devenu : ", MotACoder);

//     for (int n = 0, len = strlen(MotACoder); n < len; n++)
//     {
//         int currentLetter = MotACoder[n];
//         int encoded_letter = encode(currentLetter);


//         // On vérifie que la lettre suivant ne dépassera pas 26
//         // Ou n'est pas une lettre ASCII
//         // Si c'est le cas, on applique %26 pour revenir dans le groupe de lettre

//         // On affiche le codage
//         printf("%c", encoded_letter);
 
//         // On remet Key à 13
//         // On passe à la lettre suivante
//     }
//     printf("\n");
//     return 0;
// }


// int encode(char lettre)
// {
//     int alphabet[26]={'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

//     int encodage[26]={'m', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l'};


//     int non_encoding_letter = 'a';
//     int i = 0;
//     int find = 0;

//     while (find == 0)
//     {
//         int non_encoding_letter = alphabet[i];

//         if (lettre == non_encoding_letter)
//         {
//             int encoded_letter = encodage[i];
//             return encoded_letter;
//             find = 1;
//         }else
//         {
//             i++;
//         }

//     }
// }
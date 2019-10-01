#include "func.h"
//#include "enigma.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <windows.h>

warship *readParameters(char shipName[100])
{
    //должно быть чтение из файлика, но не вышло. В следующей версии.

    warship *output = calloc(1, sizeof(warship));// Вундервафля-сама, Ямато во втором поколении.
    if(strcmp(shipName, "Voin") == 0)
    {
        strcat(output->name, shipName);
        output->accuracy[0] = 90;
        output->accuracy[1] = 80;
        output->accuracy[2] = 60;
        output->accuracy[3] = 40;
        output->health = 19000;
        output->maxHealth = output->health;
        output->armourWide = 420;
        output->armourKazematWide = 100;
        output->armourUnderWaterWide = 200;
        output->armourKormaWide = 380;
        output->MGreloadTime = 33;
        output->PMKdamage = 340;
        output->PMKpenetration[0] = 180;
        output->PMKpenetration[1] = 100;
        output->PMKpenetration[2] = 70;
        output->PMKpenetration[3] = 20;
        output->PMKreloadTime = 4;
        output->MainGunPentration[0] = 864;
        output->MainGunPentration[1] = 494;
        output->MainGunPentration[2] = 360;
        output->MainGunPentration[3] = 200;
        output->damage = 10000;
        output->antiTorpedo = 60;
        output->countOfBK = 140;
        output->shotSound = 1;
    }
    if(strcmp(shipName, "Bizmarr") == 0) //Бисмарк-сан.
    {
        strcat(output->name, shipName);
        output->accuracy[0] = 70;
        output->accuracy[1] = 50;
        output->accuracy[2] = 20;
        output->health = 10000;
        output->maxHealth = output->health;
        output->armourWide = 320;
        output->armourKazematWide = 160;
        output->armourUnderWaterWide = 45;
        output->armourKormaWide = 110;
        output->MGreloadTime = 25;
        output->PMKdamage = 130;
        output->PMKpenetration[0] = 110;
        output->PMKpenetration[1] = 60;
        output->PMKpenetration[2] = 10;
        output->PMKreloadTime = 5;
        output->MainGunPentration[0] = 520;
        output->MainGunPentration[1] = 364;
        output->MainGunPentration[2] = 150;
        output->damage = 2000;
        output->torpedoDamage = 2500;
        output->antiTorpedo = 30;
        output->torpedoesCount = 3;
        output->countOfBK = 100;
        output->countOfTorp = 2;
        output->shotSound = 2;
    }
    if(strcmp(shipName, "Maria") == 0) //Гангут.
    {
        strcat(output->name, shipName);
        output->accuracy[0] = 60;
        output->accuracy[1] = 30;
        output->health = 5000;
        output->maxHealth = output->health;
        output->armourWide = 225;
        output->armourKazematWide = 125;
        output->armourUnderWaterWide = 75;
        output->armourKormaWide = 30;
        output->MGreloadTime = 34;
        output->PMKdamage = 150;
        output->PMKpenetration[0] = 100;
        output->PMKpenetration[1] = 50;
        output->PMKreloadTime = 9;
        output->MainGunPentration[0] = 352;
        output->MainGunPentration[1] = 207;
        output->damage = 2400;
        output->torpedoDamage =3400;
        output->antiTorpedo = 20;
        output->torpedoesCount = 5;
        output->countOfBK = 100;
        output->countOfTorp = 2;
        output->shotSound = 3;
    }
    if(strcmp(shipName, "Klipper") == 0) //Хиппер.
    {
        strcat(output->name, shipName);
        output->accuracy[0] = 80;
        output->accuracy[1] = 60;
        output->health = 3000;
        output->maxHealth = output->health;
        output->armourWide = 110;
        output->armourKazematWide = 30;
        output->armourUnderWaterWide = 10;
        output->armourKormaWide = 80;
        output->MGreloadTime = 13;
        output->PMKdamage = 90;
        output->PMKpenetration[0] = 150;
        output->PMKpenetration[1] = 90;
        output->PMKreloadTime = 3;
        output->MainGunPentration[0] = 240;
        output->MainGunPentration[1] = 130;
        output->damage = 600;
        output->torpedoDamage = 2500;
        output->antiTorpedo = 10;
        output->torpedoesCount = 4;
        output->countOfBK = 100;
        output->countOfTorp = 2;
        output->shotSound = 4;
    }
    if(strcmp(shipName, "Tezaur") == 0) //Киров.
    {
        strcat(output->name, shipName);
        output->accuracy[0] = 60;
        output->accuracy[1] = 40;
        output->health = 1100;
        output->maxHealth = output->health;
        output->armourWide = 70;
        output->armourKazematWide = 20;
        output->armourUnderWaterWide = 20;
        output->armourKormaWide = 50;
        output->MGreloadTime = 10;
        output->PMKdamage = 50;
        output->PMKpenetration[0] = 90;
        output->PMKpenetration[1] = 40;
        output->PMKreloadTime = 4;
        output->MainGunPentration[0] = 230;
        output->MainGunPentration[1] = 120;
        output->damage = 800;
        output->torpedoDamage = 3400;
        output->torpedoesCount = 5;
        output->countOfBK = 100;
        output->countOfTorp = 2;
        output->shotSound = 4;
    }
    return output;


}



fleet *loadFleet()
{

    fleet *output = malloc(sizeof(fleet));

    FILE *fleetSetup;
    if ((fleetSetup = fopen("fleetSetup.txt", "r")) == NULL)
    {
        printf("\nCheck file: fleetSetup.txt \n\n");
        return 0;
    }
    char input[104];
    char shipNumberChar[3];
    int i = 0; //многоразовый счетчик
    int ShipNumber = 0;
    for(; i < 100; i++)
        output->warship[i] = calloc(1, sizeof(warship));
    i = 0;
    while(!feof(fleetSetup))
    {
        fgets(input, 104, fleetSetup);
        while(input[i] != 32)
        {
            shipNumberChar[i] = input[i];
            i++;
        } //бег до пробела
        ShipNumber = atoi(shipNumberChar);
         for(int j = 0; j < 104; j++)
                input[j] = input[j + i + 1];//сдвинуть название левее, убрав цифры. Да, это лютый костыль.
        i = 0;
        while(input[i] != 0)
            i++;
        input[i-1] = 0;
        i = 0;

        output->warship[ShipNumber] = readParameters(input);
    }

    fclose(fleetSetup);
    int biggest = 0;
    int foo = 0;
    for(i = 0; i < 100; i++)
    {
        if(output->warship[i]->MGreloadTime > biggest)
            biggest = output->warship[i]->MGreloadTime;
        //найти наибольшее КД, затем - еще цикл, где каждому домножить.
    }
    for (i = 0; i < 100;i++) {
        if (output->warship[i]->damage > 0 && output->warship[i] != NULL)
        {
            foo = output->warship[i]->MGreloadTime;
            output->warship[i]->numberOfGkSHots = biggest / foo;
            foo = output->warship[i]->PMKreloadTime;
            output->warship[i]->numberOfPMKShots = biggest / foo;
        }
    }
    for (i = 0; i < 100; ++i) {
            if(output->warship[i]->health == 0)
                output->warship[i] = NULL;
    }
    return output;
}

void shipCondition(warship *input)
{
    if(input != NULL)
    {
        if(input->health > 0)
        {
            float temp = 100 * input->health / input->maxHealth;
            printf("%s is live. Health: %d(%d %%).\n", input->name, input->health, (int)temp);
        }
        else
            printf("%s`s guns are gone silent forever.\n", input->name);
    } else
        printf("there are is no this ship\n");

}

void fleetCondition(fleet *fleetInput)
{
    printf("are live: \n");
    float temp = 0;
    for(int i = 0; i < 100; i++)
    {
        if(fleetInput->warship[i] != NULL && fleetInput->warship[i]->health > 0)
        {
            temp = 100 * fleetInput->warship[i]->health / fleetInput->warship[i]->maxHealth;
            printf(" type: %s number: %d health: %d %% ammo: %d.\n", fleetInput->warship[i]->name, i, (int)temp, fleetInput->warship[i]->countOfBK);
        }
    }
    printf("are on the bottom of the Ocean:\n");
    for(int i = 0; i < 100; i++)
    if(fleetInput->warship[i] != NULL && fleetInput->warship[i]->health <= 0)
    {
            printf(" type: %s number: %d health: 0.\n", fleetInput->warship[i]->name, i);
    }
}

warship *torpedoes(warship *target, warship *attacker)
{
    if(attacker->torpedoesCount == 0 || attacker->countOfTorp == 0)
    {
        printf("attacket hasn`t any torpedoes.\n");
        return target;
    }
    int vpupal = 0 + rand() % attacker->torpedoesCount;
    target->health = target->health - vpupal * attacker->torpedoDamage * (100 - target->antiTorpedo) / 100;
    float temp = 100 * target->health / target->maxHealth;
    printf("%d torpedoes hit! target health: %d %%.\n", vpupal, (int)temp);
    if(target->health < 0)
        printf("target destroyed!\n");
    attacker->countOfTorp--;
    return target;
}

warship *shot(warship *attacker, warship *target, int numberOfGKShots,  int distance, int angle)
{
    if(attacker == NULL || target == NULL)
        return NULL;
    if(target->health <= 0)
    {
        printf(" target is destroyed.\n");
        return target;
    }
    int vpupal = 0 + rand() % 100;
    int vpupalGK = 0;
    switch (attacker->shotSound)
    {
        case 0:
            break;
        case 1:
            system("shot1.exe");
            break;
        case 2:
            system("shot2.exe");
            break;
        case 3:
            system("shot3.exe");
            break;
        case 4:
            system("shot4.exe");
            break;
        default:
            printf("call Oleg and say: Oleg, check sounds.\n");
            break;
    }

    for(int i = 0; i < numberOfGKShots && target->health > 0; i++)
    {
        attacker->countOfBK--;
        if((attacker->accuracy[distance] + i * 10) >= vpupal && attacker->accuracy[distance] > 0) // попал ли по кораблю.
        {
        vpupalGK = 0 + rand() % 100;
        vpupal = 0 + rand() % 100;
        if(vpupalGK > 0 && vpupalGK < 50) // на первое время - шанс из попадания в корабль словить в цитадель - половина. Так проще.
        {
            switch(angle)
            {
            case  0:
                if(target->armourKormaWide < attacker->MainGunPentration[distance])
                {
                    if (vpupalGK < 40 && vpupalGK > 10)
                    {
                        printf(" target is critically damaged! \n");
                        target->health -= attacker->damage;
                        if(vpupalGK > 23 && vpupal < 27 && target->countOfBK > 0)
                        {
                            printf(" target's ammunition cellar detonated!\n");
                            target->health = -1;
                        }
                        if(target->health < 0)
                            printf(" Target destroyed!\n");
                    }
                }
                else
                    printf(" armor is not penetrated!\n");
            break;
            case 45:
                if(target->armourWide * 1.41 <= attacker->MainGunPentration[distance])
                {
                    printf(" target is critically damaged! \n");
                    target->health -= attacker->damage;
                    if(vpupalGK > 23 && vpupal < 27 && target->countOfBK > 0)
                    {
                        printf(" target's ammunition cellar detonated!\n");
                        target->health = -1;
                    }
                    if(target->health < 0)
                        printf(" Target destroyed!\n");
                }
                else
                {
                    printf(" armor is not penetrated!\n");
                }
                break;
            case 90:
                if(target->armourWide <= attacker->MainGunPentration[distance])
                {
                    printf(" target is critically damaged! \n");
                    target->health -= attacker->damage;
                    if(vpupalGK > 23 && vpupal < 27 && target->countOfBK > 0)
                    {
                        printf(" target's ammunition cellar detonated!\n");
                        target->health = -1;
                    }
                    if(target->health < 0)
                        printf(" Target destroyed!\n");
                }
                else
                {
                    printf(" armor is not penetrated!\n");
                }
                break;
            case 30:
                if(target->armourWide * 2 <= attacker->MainGunPentration[distance])
                {
                    printf(" target is critically damaged! \n");
                    target->health -= attacker->damage;
                    if(vpupalGK > 23 && vpupal < 27 && target->countOfBK > 0)
                    {
                        printf(" target's ammunition cellar detonated!\n");
                        target->health = -1;
                    }
                    if(target->health < 0)
                        printf(" Target destroyed!\n");
                }
                else
                {
                    printf(" armor is not penetrated!\n");
                }
                break;
                case 60:
                    if(target->armourWide * 1.15 <= attacker->MainGunPentration[distance])
                    {
                        printf(" target is critically damaged! \n");
                        target->health -= attacker->damage;
                        if(vpupalGK > 23 && vpupal < 27 && target->countOfBK > 0)
                        {
                            printf(" target's ammunition cellar detonated!\n");
                            target->health = -1;
                        }
                        if(target->health < 0)
                            printf(" Target destroyed!\n");
                    }
                    else
                    {
                        printf(" armor is not penetrated!\n");
                    }
                    break;
            default:
                printf("error: angle is incorrect \n");
                break;
            }
        }
        if(vpupalGK >= 50 && vpupalGK < 75)
        {
            switch(angle)
            {
            case  0:
                if(target->armourUnderWaterWide < attacker->MainGunPentration[distance])
                {
                    if (vpupalGK < 67 && vpupalGK > 58)
                    {
                        target->health -= attacker->damage/3;
                        printf(" target damaged! \n");
                        if(target->health < 0)
                            printf(" Target destroyed!\n");
                    }
                }
                else
                    printf(" armor is not penetrated!\n");
                break;
            case 45:
                if(target->armourUnderWaterWide * 1.41 <= attacker->MainGunPentration[distance]/1.2)
                {
                    target->health -= attacker->damage/3;
                    printf(" target damaged! \n");
                    if(target->health < 0)
                        printf(" Target destroyed!\n");
                }
                else
                    printf(" armor has not penetrated!\n");
                break;
            case 90:
                if(target->armourUnderWaterWide <= attacker->MainGunPentration[distance])
                {
                    target->health -= attacker->damage/3;
                    printf(" target damaged! \n");
                    if(target->health < 0)
                        printf(" Target destroyed!\n");
                }
                else
                    printf(" target has not damaged! \n");
                break;
            case 30:
                if(target->armourUnderWaterWide * 2 <= attacker->MainGunPentration[distance])
                {
                    target->health -= attacker->damage/3;
                    printf(" target damaged! \n");
                    if(target->health < 0)
                        printf(" Target destroyed!\n");
                }
                else
                    printf(" armor is too strong! \n");
                break;
            case 60:
                if(target->armourUnderWaterWide * 1.15 <= attacker->MainGunPentration[distance])
                {
                    printf(" target damaged! \n");
                    target->health -= attacker->damage;
                    if(target->health < 0)
                        printf(" Target destroyed!\n");
                }
                else
                {
                    printf(" armor is not penetrated!\n");
                }
                break;
            default:
                printf("error: angle is incorrect \n");
                break;
            }
        }
        if(vpupalGK > 75)
        {
            printf(" getroffen! ");
            if((target->armourKazematWide / 2) > attacker->MainGunPentration[distance])
            {
                printf(" target has not damaged!\n");
            }
            else
            {
                printf(" casemate has damaged! \n");
                target->health -= attacker->damage/3;
                if(target->health <= 0)
                    printf(" Target destroyed!\n");
            }

        }
    }
    else
    {
        printf(" Miss! \n");
    }

    }
    float temp = 100 * target->health / target->maxHealth;
    printf("target health: %d %%.\n", (int)temp);
    return target;
}
warship *mines(warship *input)
{
    int vpupal = 0 + rand() % 1000;
    if(vpupal > 500)
    {
        printf("explosions under water!\n");
        vpupal /= 50;
        input->health -= input->maxHealth / 100 * vpupal;
    } else
    {
        printf("all right.\n");
    }
    return input;
}


warship *shotPMK(warship *attacker, warship *targetPMK, int distance, int angle, int numberOfPMKshots) {
    if(attacker == NULL || targetPMK == NULL)
        return NULL;

    int vpupalPMK = 0;
    int vpupal = 0;
    if(targetPMK->health <= 0)
        {
            printf(" PMK-target is under water.\n");
            return targetPMK;
        }
    for (int i = 0; i < numberOfPMKshots && targetPMK->health >= 0; i++) {
        vpupal = 0 + rand() % 100;
        if (vpupal < (attacker->accuracy[distance] + i * 7) && attacker->accuracy[distance] > 0)
        {
            vpupalPMK = 0 + rand() % 100;
            if (vpupalPMK <= 30) // треть попаданий по цитадели, другая треть по казематам, третья в оконечности. Чтобы и линкорам, и крейсерам, и эсминце-лолям залетало.
            {
                switch (angle) {
                    case 45:
                        if (targetPMK->armourWide * 1.41 < attacker->PMKpenetration[distance]) {
                            printf(" PMK-target is critically damaged! \n");
                            targetPMK->health -= attacker->PMKdamage;
                            if(vpupalPMK > 15 && vpupal < 20 && targetPMK->countOfBK > 0)
                            {
                                printf(" PMK-target's ammunition cellar detonated!\n");
                                targetPMK->health = -1;
                            }
                            if(targetPMK->health < 0)
                                printf(" PMK-target destroyed!\n");
                        } else {
                            printf(" PMK-target`s armor is not penetrated!\n");
                        }
                        break;
                    case 90:
                        if (targetPMK->armourWide < attacker->PMKpenetration[distance]) {
                            printf(" PMK-target is critically damaged! \n");
                            targetPMK->health -= attacker->PMKdamage;
                            if(vpupalPMK > 15 && vpupal < 20 && targetPMK->countOfBK > 0)
                            {
                                printf(" PMK-target's ammunition cellar detonated!\n");
                                targetPMK->health = -1;
                            }
                            if(targetPMK->health < 0)
                                printf(" PMK-target destroyed!\n");
                        } else {
                            printf(" PMK-target`s armor is not penetrated!\n");
                        }
                        break;
                    case 30:
                        if (targetPMK->armourWide * 2 < attacker->PMKpenetration[distance]) {
                            printf(" PMK-target is critically damaged! \n");
                            targetPMK->health -= attacker->PMKdamage;
                            if(vpupalPMK > 15 && vpupal < 20 && targetPMK->countOfBK > 0)
                            {
                                printf(" PMK-target's ammunition cellar detonated!\n");
                                targetPMK->health = -1;
                            }
                            if(targetPMK->health < 0)
                                printf(" PMK-target destroyed!\n");
                        } else {
                            printf(" PMK-target`s armor is not penetrated!\n");
                        }

                        break;
                    case 0:
                        if(targetPMK->armourKormaWide < attacker->PMKpenetration[distance])
                        {
                            if (vpupalPMK < 27 && vpupalPMK > 5)
                            {
                                printf(" PMK-target is critically damaged! \n");
                                targetPMK->health -= attacker->PMKdamage;
                                if(vpupalPMK > 15 && vpupal < 20 && targetPMK->countOfBK > 0)
                                {
                                    printf(" PMK-target's ammunition cellar detonated!\n");
                                    targetPMK->health = -1;
                                }
                                if(targetPMK->health < 0)
                                    printf(" PMK-target destroyed!\n");
                            }
                        }
                        else
                        {
                            printf(" armor is not penetrated!\n");
                        }
                        break;
                    case 60:
                        if(targetPMK->armourWide * 1.15 < attacker->PMKpenetration[distance])
                        {
                            printf(" PMK-target is critically damaged! \n");
                            targetPMK->health -= attacker->PMKdamage;
                            if(vpupalPMK > 23 && vpupal < 27)
                            {
                                printf(" PMK-target's ammunition cellar detonated!\n");
                                targetPMK->health = -1;
                            }
                            if(targetPMK->health < 0)
                                printf(" PMK-Target destroyed!\n");
                        }
                        else
                        {
                            printf(" PMK-target`s armor is not penetrated!\n");
                        }
                        break;
                    default:
                        printf("error: angle is incorrect \n");
                        break;
                }
            }
            if (vpupalPMK > 30) {
                switch (angle) {
                    case 0:
                        if(targetPMK->armourKazematWide < attacker->PMKpenetration[distance])
                        {
                            if (vpupalPMK < 65 && vpupalPMK > 55)
                            {
                                printf(" PMK-target is damaged! \n");
                                targetPMK->health -= attacker->damage / 4;
                                if(targetPMK->health < 0)
                                    printf(" PMK-Target destroyed!\n");
                            }
                        }
                        else
                        {
                            printf(" PMK-target`s armor is not penetrated!\n");
                        }
                    break;
                    case 45:
                        if (targetPMK->armourKazematWide * 1.41 < attacker->PMKpenetration[distance]) {
                            printf(" PMK-target is damaged! \n");
                            targetPMK->health -= attacker->PMKdamage / 4;
                            if(targetPMK->health < 0)
                                printf(" PMK-target destroyed!\n");
                        } else {
                            printf(" PMK-target`s armor is not penetrated!\n");
                        }
                        break;
                    case 90:
                        if (targetPMK->armourKazematWide < attacker->PMKpenetration[distance]) {
                            printf(" PMK-target is damaged! \n");
                            targetPMK->health -= attacker->PMKdamage / 4;
                            if(targetPMK->health < 0)
                                printf(" PMK-target destroyed!\n");
                        } else {
                            printf(" PMK-target`s armor is not penetrated!\n");
                        }
                        break;
                    case 30:
                        if (targetPMK->armourKazematWide * 2 < attacker->PMKpenetration[distance]) {
                            printf(" PMK-target is damaged! \n");
                            targetPMK->health -= attacker->PMKdamage / 4;
                            if(targetPMK->health < 0)
                                printf(" PMK-target destroyed!\n");
                        } else {
                            printf(" PMK-target`s armor is not penetrated!\n");
                        }
                        break;
                    case 60:
                        if(targetPMK->armourKazematWide * 1.15 <= attacker->PMKpenetration[distance])
                        {
                            printf(" PMK-target is damaged! \n");
                            targetPMK->health -= attacker->PMKdamage / 4;
                            if(targetPMK->health < 0)
                                printf(" PMK-Target destroyed!\n");
                        }
                        else
                        {
                            printf(" PMK-target`s armor is not penetrated!\n");
                        }
                        break;
                    default:
                        printf("error: angle is incorrect. \n");
                        break;
                }
            }
        }
        else
            printf(" PMK missed!\n");
    }
    float temp = 100 * targetPMK->health / targetPMK->maxHealth;
    printf("target-PMK health: %d %%.\n", (int)temp);
    return targetPMK;
}

void filePrint(char inputName[10])
{
    FILE * hi;
    char n;
    hi=fopen(inputName,"rt");
    while(!feof(hi))
    {
        fscanf(hi,"%c",&n);
        printf("%c",n);
    }
    fclose(hi);
}

fleet *rounb(fleet *allShips)
{
    char inputCommand[20];
    int artInDatGK[2];
    int inputHealth = 0;
    int inputName1 = 0;
    int inputName2 = 0;

    scanf("%s", &inputCommand);
    if(strcoll("exit", inputCommand) == 0 && strlen(inputCommand) == 4)
    {
        allShips->exitFactor = 0;
        return allShips;
    }
    if(strcmp(inputCommand, "condition") == 0)
    {
        scanf("%d", &inputName1);
        if(inputName1 > 99 || inputName1 < 1)
            printf("there is no such ship.\n");
        else
            shipCondition(allShips->warship[inputName1]);
    }
    if(strcmp("situation", inputCommand) == 0)
    {
        fleetCondition(allShips);
    }
    if(strcmp("ficha", inputCommand) == 0)
    {
        scanf("%d", &inputName1);
        switch(inputName1)
        {
            case 1:
            {
                filePrint("sw.txt");
                break;
            }
            case 2:
            {
                filePrint("jp.txt");
                break;
            }
            case 3:
            {
                filePrint("su.txt");
                break;
            }
        }
    }
    if(strcmp(inputCommand, "fora") == 0)
    {
        scanf("%d %s %d", &inputName1, &inputCommand, &inputHealth);
        if(inputName1 > 99)
            printf("there is no such ship.\n");
        else
            if(strcmp(inputCommand, "health") == 0)
            {
                printf("%s`s health is %d.\n", allShips->warship[inputName1]->name, inputHealth);
                allShips->warship[inputName1]->health = inputHealth;
            }
            if(strcmp(inputCommand, "accuracy") == 0)
            {
                for (int i = 0; i < 7 && allShips->warship[inputName1]->accuracy > 0; ++i)
                {
                    allShips->warship[inputName1]->accuracy[i] += inputHealth;
                    if(allShips->warship[inputName1]->accuracy[i] > 100)
                        allShips->warship[inputName1]->accuracy[i] = 99;
                }
                printf("%s`s accuracy on all distances increased for %d percents.\n", allShips->warship[inputName1], inputHealth);
            }
    }
    if(strcmp("pmk", inputCommand) == 0)
    {
        scanf("%d %d %d %d", &inputName1, &inputName2, &artInDatGK[0], &artInDatGK[1]);
        if(allShips->warship[inputName1] == NULL || allShips->warship[inputName2] == NULL)
        {
            printf("This ships isn`t be");
            return allShips;
        }
        if (inputName1 > 0 && inputName1 < 100 && inputName2 > 0 && inputName2 < 100 && artInDatGK[0] > -1 && artInDatGK[0] < 8)
        {
            printf("target for %s`s PMK is %s.\n", allShips->warship[inputName1]->name, allShips->warship[inputName2]->name);
            allShips->warship[inputName1]->targetPMK[0] = inputName2;
            allShips->warship[inputName1]->targetPMK[1] = artInDatGK[0];
            allShips->warship[inputName1]->targetPMK[2] = artInDatGK[1];
        }
        else
            printf("command is incorrect.\n");
    }
    if(strcmp("torpedoes", inputCommand) == 0)
    {
        scanf("%d %d", &inputName1, &inputName2);
        if(allShips->warship[inputName1] == NULL || allShips->warship[inputName2] == NULL)
        {
            printf("This ships isn`t be\n");
            return allShips;
        }
        allShips->warship[inputName2] = torpedoes(allShips->warship[inputName2], allShips->warship[inputName1]);
    }
    if(strcmp("shot", inputCommand) == 0)
    {
        scanf("%d %d %d %d", &inputName1, &inputName2, &artInDatGK[0], &artInDatGK[1]);
        if(allShips->warship[inputName1] == NULL || allShips->warship[inputName2] == NULL)
        {
            printf("This ships isn`t be\n");
            return allShips;
        }
        if(allShips->warship[inputName1]->targetPMK[0] == 0)
        {
            allShips->warship[inputName1]->targetPMK[0] = inputName2;
            allShips->warship[inputName1]->targetPMK[1] = artInDatGK[0];
            allShips->warship[inputName1]->targetPMK[2] = artInDatGK[1];
        }
        if (inputName1 > 0 && inputName1 < 100 && inputName2 > 0 && inputName2 < 100 && artInDatGK[0] > -1 && artInDatGK[0] < 8)
        {
            if(allShips->warship[inputName1]->countOfBK > 0)
            {
                allShips->warship[inputName2] = shot(allShips->warship[inputName1], allShips->warship[inputName2],  allShips->warship[inputName1]->numberOfGkSHots, artInDatGK[0], artInDatGK[1]);
            } else
                printf("ammunition cellar is emty.\n");
            printf("PMK:\n");
            allShips->warship[allShips->warship[inputName1]->targetPMK[0]] = shotPMK(allShips->warship[inputName1], allShips->warship[allShips->warship[inputName1]->targetPMK[0]], allShips->warship[inputName1]->targetPMK[1], allShips->warship[inputName1]->targetPMK[2], allShips->warship[inputName1]->numberOfPMKShots);
            allShips->warship[inputName1]->targetPMK[0] = 0;
        }
        else
            printf("command is incorrect.\n");
    }
    return allShips;// справедливый конец функции.
}
/*
 TODO
 написать сочные звуки;
 глубинные бомбы и вероятность поражения подлодки;
 мины;
 добавить кучу торпедных катеров и подлодок;
 сделать динамические массивы-полухэшмап;
 сделать вынесение всего в структуры;
 сделать параметры в файле;
*/

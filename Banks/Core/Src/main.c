/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "stm32f1xx_hal.h"


/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */
struct BankaHesabi{
	char isim[50];
	int bankanumarasi;
	int balance;
	int bakiye;
};
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
//static void MX_GPIO_Init(void);
//static void MX_USART1_UART_Init(void);
/* USER CODE BEGIN PFP */
void UART_Gonder(char* mesaj) {
	HAL_UART_Transmit(&huart1, (uint8_t*)mesaj, strlen(mesaj), HAL_MAX_DELAY);
}

void UART_Alinan(char* buffer, uint16_t bufferSize) {
	HAL_UART_Receive(&huart1, (uint8_t*)buffer, bufferSize, HAL_MAX_DELAY);
}

void paraYatir(struct BankaHesabi* hesap, int miktar) {
	hesap->bakiye += miktar;
	char mesaj[100];
	sprintf(mesaj, "%d TL tutarinda para yatirma islemi basarili.\n", miktar);
	UART_Gonder(mesaj);
}

void paraCek(struct BankaHesabi* hesap, int miktar) {
	if (hesap->bakiye >= miktar) {
		hesap->bakiye -= miktar;
		char mesaj[100];
		sprintf(mesaj, "%d TL tutarinda para cekme islemi basarili.\n", miktar);
		UART_Gonder(mesaj);
	} else {
		char mesaj[100];
		sprintf(mesaj, "Yetersiz bakiye. %d TL tutari cekilemiyor.\n", miktar);
		UART_Gonder(mesaj);
	}
}

void paraGonder(struct BankaHesabi* hesap, int miktar)
{
	if(hesap->bakiye >= miktar)
	{
		hesap->bakiye -= miktar;
		char mesaj[100];
		sprintf(mesaj, "%d TL tutarinda para gonderilmistir..\n", miktar);
		UART_Gonder(mesaj);
	}
	else
	{
		char mesaj[100] = {0};
		sprintf(mesaj, "Yetersiz bakiye. %d TL tutar gonderilemiyor..\n", miktar);
		UART_Gonder(mesaj);

	}
}

void krediCekme(struct BankaHesabi* hesap, int miktar)
{
	if(hesap->bakiye >= miktar)
	{
		hesap->bakiye -= miktar;
		char mesaj[100];
		sprintf(mesaj, "%d TL tutarinda kredi cekilmistir..\n", miktar);
		UART_Gonder(mesaj);
	}
	else
	{
		char mesaj[100];
		sprintf(mesaj, "Girdiginiz deger 1000-50000 arasinda olmali. %d TL uygun bir fiyat degil.\n", miktar);
		UART_Gonder(mesaj);

	}
}

void borcOdeme(struct BankaHesabi* hesap, int miktar)
{
	if(hesap->bakiye >= miktar)
	{
		hesap->bakiye -= miktar;
		char mesaj[100];
		sprintf(mesaj, "%d TL tutarinda borcunuz odenmistir..\n", miktar);
		UART_Gonder(mesaj);
	}
	else
	{
		char mesaj[100];
		sprintf(mesaj, "Yetersiz bakiye. %d TL tutarindaki borcunuz odenemiyor...\n", miktar);
		UART_Gonder(mesaj);

	}
}

void dolarDoviz(struct BankaHesabi* hesap, int miktar)
{
	if(hesap->bakiye >= miktar)
	{
		hesap->bakiye -= miktar;
		miktar = miktar / 27.76;
		char mesaj[100];
		sprintf(mesaj, "%d TL tutarinda dolar alinmistir..\n", miktar);
		UART_Gonder(mesaj);
	}
	else
	{
		char mesaj[100];
		sprintf(mesaj, "Yetersiz bakiye. %d TL tutarinda  dolar alinamiyor...\n", miktar);
		UART_Gonder(mesaj);

	}
}

void euroDoviz(struct BankaHesabi* hesap, int miktar)
{
	if(hesap->bakiye >= miktar)
	{
		hesap->bakiye -= miktar;
		miktar = miktar / 30.34;
		char mesaj[100];
		sprintf(mesaj, "%d TL tutarinda euro alinmistir..\n", miktar);
		UART_Gonder(mesaj);
	}
	else
	{
		char mesaj[100];
		sprintf(mesaj, "Yetersiz bakiye. %d TL tutarinda  euro alinamiyor...\n", miktar);
		UART_Gonder(mesaj);

	}
}

void altinAlma(struct BankaHesabi* hesap, int miktar)
{
	if(hesap->bakiye >= miktar)
	{
		hesap->bakiye -= miktar;
		char mesaj[100];
		sprintf(mesaj, "%d TL tutarinda altin alinmistir..\n", miktar);
		UART_Gonder(mesaj);
	}
	else
	{
		char mesaj[100];
		sprintf(mesaj, "Yetersiz bakiye. %d TL tutarinda  altin alinamiyor...\n", miktar);
		UART_Gonder(mesaj);

	}
}

void suFatura(struct BankaHesabi* hesap, int miktar)
{
	if(hesap->bakiye >= miktar)
	{
		hesap->bakiye -= miktar;
		char mesaj[100];
		sprintf(mesaj, "%d TL tutarinda su faturaniz odenmistir..\n", miktar);
		UART_Gonder(mesaj);
	}
	else
	{
		char mesaj[100];
		sprintf(mesaj, "Yetersiz bakiye. %d TL tutarindaki su faturaniz odenemiyor...\n", miktar);
		UART_Gonder(mesaj);

	}
}

void dogalgazFatura(struct BankaHesabi* hesap, int miktar)
{
	if(hesap->bakiye >= miktar)
	{
		hesap->bakiye -= miktar;
		char mesaj[100];
		sprintf(mesaj, "%d TL tutarinda dogalgaz faturaniz odenmistir..\n", miktar);
		UART_Gonder(mesaj);
	}
	else
	{
		char mesaj[100];
		sprintf(mesaj, "Yetersiz bakiye. %d TL tutarindaki dogalgaz faturaniz odenemiyor...\n", miktar);
		UART_Gonder(mesaj);

	}
}

void elektrikFatura(struct BankaHesabi* hesap, int miktar)
{
	if(hesap->bakiye >= miktar)
	{
		hesap->bakiye -= miktar;
		char mesaj[100];
		sprintf(mesaj, "%d TL tutarinda elektrik faturaniz odenmistir..\n", miktar);
		UART_Gonder(mesaj);
	}
	else
	{
		char mesaj[100];
		sprintf(mesaj, "Yetersiz bakiye. %d TL tutarindaki elektrik faturaniz odenemiyor...\n", miktar);
		UART_Gonder(mesaj);

	}
}


void bakiyeGoster(struct BankaHesabi hesap) {
	char mesaj[100];
	sprintf(mesaj, "Hesap Sahibi: %s\nHesap Numarasi: %d\nBakiye: %d TL\n", hesap.isim, hesap.bankanumarasi, hesap.bakiye);
	UART_Gonder(mesaj);
}
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void)
{
	/* USER CODE BEGIN 1 */


	/* USER CODE END 1 */

	/* MCU Configuration--------------------------------------------------------*/

	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	HAL_Init();

	/* USER CODE BEGIN Init */

	/* USER CODE END Init */

	/* Configure the system clock */
	//SystemClock_Config();

	/* USER CODE BEGIN SysInit */

	/* USER CODE END SysInit */

	/* Initialize all configured peripherals */
	//MX_GPIO_Init();
	//MX_USART1_UART_Init();
	/* USER CODE BEGIN 2 */

	struct BankaHesabi hesap;
	strcpy(hesap.isim, "Ali Veli"); // strcpy yerine ne kullNILbşlir

	char girisBuffer[50];


	UART_Gonder("Hesap numaranizi giriniz: ");
	UART_Alinan(girisBuffer, sizeof(girisBuffer));
	hesap.bankanumarasi = atoi(girisBuffer);

	UART_Gonder("Baslangic bakiyenizi giriniz: ");
	UART_Alinan(girisBuffer, sizeof(girisBuffer));
	hesap.bakiye = atoi(girisBuffer);


	/* USER CODE END 2 */

	/* Infinite loop */
	/* USER CODE BEGIN WHILE */
	while (1)
	{

		/* USER CODE END WHILE */

		/* USER CODE BEGIN 3 */

		UART_Gonder("\n\nANA MENU\n");
		UART_Gonder("--------------\n");
		UART_Gonder("1. Bakiye Goruntule\n");
		UART_Gonder("2. Para Yatirma\n");
		UART_Gonder("3. Para Cekme\n");
		UART_Gonder("4. Para Gonderme\n");
		UART_Gonder("5. Kredi Cekme\n");
		UART_Gonder("6. Borc Odeme\n");
		UART_Gonder("7. Dolar Alma\n");
		UART_Gonder("8. Euro Alma\n");
		UART_Gonder("9. Altin Alma\n");
		UART_Gonder("10. Su faturası odeme\n");
		UART_Gonder("11. Dogalgaz faturası odeme\n");
		UART_Gonder("12. Elektrik faturası odeme\n");
		UART_Gonder("13. Cıkıs..\n");

		for (int i; i<10; i++)
		{
			if(i == 0)
			{
				UART_Gonder("Seciminizi giriniz: ");
				HAL_UART_DMAPause(&huart1);
				i++;
			}
			else
			{
				HAL_UART_DMAResume(&huart1);
				i++;
			}
		}

		UART_Alinan(girisBuffer, sizeof(girisBuffer));

		int secim = atoi(girisBuffer);
		int miktar;

		switch (secim) {
		case 1:
			bakiyeGoster(hesap);
			break;
		case 2:
			UART_Gonder("Yatirilacak miktar: ");
			UART_Alinan(girisBuffer, sizeof(girisBuffer));
			miktar = atoi(girisBuffer);
			paraYatir(&hesap, miktar);
			break;
		case 3:
			UART_Gonder("Cekilecek miktar: ");
			UART_Alinan(girisBuffer, sizeof(girisBuffer));
			miktar = atoi(girisBuffer);
			paraCek(&hesap, miktar);
			break;
		case 4:
			UART_Gonder("Ne kadar para gondermek istersiniz: ");
			UART_Alinan(girisBuffer, sizeof(girisBuffer));
			miktar = atoi(girisBuffer);
			paraGonder(&hesap, miktar);
			break;

		case 5:
			UART_Gonder("Ne kadar kredi cekmek istersiniz: ");
			UART_Alinan(girisBuffer, sizeof(girisBuffer));
			miktar = atoi(girisBuffer);
			krediCekme(&hesap, miktar);
			break;
		case 6:
			UART_Gonder("Borcunuz kac TL'dir: ");
			UART_Alinan(girisBuffer, sizeof(girisBuffer));
			miktar = atoi(girisBuffer);
			borcOdeme(&hesap, miktar);
			break;
		case 7:
			UART_Gonder("Kac TL'lik dolar almak istersiniz: ");
			UART_Alinan(girisBuffer, sizeof(girisBuffer));
			miktar = atoi(girisBuffer);
			dolarDoviz(&hesap, miktar);
			break;
		case 8:
			UART_Gonder("Kac TL'lik euro almak istersiniz: ");
			UART_Alinan(girisBuffer, sizeof(girisBuffer));
			miktar = atoi(girisBuffer);
			euroDoviz(&hesap, miktar);
			break;
		case 9:
			UART_Gonder("Kac TL'lik altin almak istersiniz: ");
			UART_Alinan(girisBuffer, sizeof(girisBuffer));
			miktar = atoi(girisBuffer);
			altinAlma(&hesap, miktar);
			break;
		case 10:
			UART_Gonder("Su  faturaniz kac TL'dir: ");
			UART_Alinan(girisBuffer, sizeof(girisBuffer));
			miktar = atoi(girisBuffer);
			suFatura(&hesap, miktar);
			break;
		case 11:
			UART_Gonder("Dogalgaz faturaniz kac TL'dir: ");
			UART_Alinan(girisBuffer, sizeof(girisBuffer));
			miktar = atoi(girisBuffer);
			dogalgazFatura(&hesap, miktar);
			break;
		case 12:
			UART_Gonder("Elektrik faturaniz kac TL'dir: ");
			UART_Alinan(girisBuffer, sizeof(girisBuffer));
			miktar = atoi(girisBuffer);
			elektrikFatura(&hesap, miktar);
			break;
		case 13:
			UART_Gonder("Programdan cikiliyor.\n");
			return 0;
		default:
			UART_Gonder("Gecersiz secim. Lutfen tekrar deneyin.\n");
			break;
		}
		/* USER CODE END 3 */
	}

	/**
	 * @brief System Clock Configuration
	 * @retval None
	 */

	/* System Clock Configuration */
	//void SystemClock_Config(void)
	{
		RCC_OscInitTypeDef RCC_OscInitStruct = {0};
		RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

		/** Initializes the RCC Oscillators according to the specified parameters
		 * in the RCC_OscInitTypeDef structure.
		 */
		RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
		RCC_OscInitStruct.HSIState = RCC_HSI_ON;
		RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
		RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
		if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
		{
			Error_Handler();
		}

		/** Initializes the CPU, AHB and APB buses clocks
		 */
		RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
				|RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
		RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
		RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
		RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
		RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

		if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
		{
			Error_Handler();
		}
	}

	/**
	 * @brief USART1 Initialization Function
	 * @param None
	 * @retval None
	 */
	//static void MX_USART1_UART_Init(void)
	{

		/* USER CODE BEGIN USART1_Init 0 */

		/* USER CODE END USART1_Init 0 */

		/* USER CODE BEGIN USART1_Init 1 */

		/* USER CODE END USART1_Init 1 */
		huart1.Instance = USART1;
		huart1.Init.BaudRate = 9600;
		huart1.Init.WordLength = UART_WORDLENGTH_8B;
		huart1.Init.StopBits = UART_STOPBITS_1;
		huart1.Init.Parity = UART_PARITY_NONE;
		huart1.Init.Mode = UART_MODE_TX_RX;
		huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
		huart1.Init.OverSampling = UART_OVERSAMPLING_16;
		if (HAL_UART_Init(&huart1) != HAL_OK)
		{

			/* USER CODE BEGIN USART1_Init 2 */

			/* USER CODE END USART1_Init 2 */

		}

		/**
		 * @brief GPIO Initialization Function
		 * @param None
		 * @retval None
		 */
		//static void MX_GPIO_Init(void)
		{
			/* USER CODE BEGIN MX_GPIO_Init_1 */
			/* USER CODE END MX_GPIO_Init_1 */

			/* GPIO Ports Clock Enable */
			__HAL_RCC_GPIOD_CLK_ENABLE();
			__HAL_RCC_GPIOA_CLK_ENABLE();

			/* USER CODE BEGIN MX_GPIO_Init_2 */
			/* USER CODE END MX_GPIO_Init_2 */
		}

		/* USER CODE BEGIN 4 */

		/* USER CODE END 4 */

		/**
		 * @brief  This function is executed in case of error occurrence.
		 * @retval None
		 */
		//void Error_Handler(void)
		{
			/* USER CODE BEGIN Error_Handler_Debug */
			/* User can add his own implementation to report the HAL error return state */
			__disable_irq();
			while (1)
			{
			}
			/* USER CODE END Error_Handler_Debug */
		}
	}
}

#ifdef  USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t *file, uint32_t line)
{
	/* USER CODE BEGIN 6 */
	/* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
	/* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

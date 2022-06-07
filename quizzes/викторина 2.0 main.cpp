#include "викторина 2.0.h"

int main()
{
	mciSendString(TEXT("open \"correct.mp3\" type mpegvideo alias mp3"), NULL, 0, NULL);
	mciSendString(TEXT("open \"wrong.mp3\" type mpegvideo alias mp3"), NULL, 0, NULL);
	mciSendString(TEXT("open \"gong.mp3\" type mpegvideo alias mp3"), NULL, 0, NULL);
	mciSendString(TEXT("open \"end.mp3\" type mpegvideo alias mp3"), NULL, 0, NULL);
	mciSendString(TEXT("open \"start.mp3\" type mpegvideo alias mp3"), NULL, 0, NULL);
	mciSendString(TEXT("open \"phone.mp3\" type mpegvideo alias mp3"), NULL, 0, NULL);
	mciSendString(TEXT("open \"background_music.mp3\" type mpegvideo alias mp3"), NULL, 0, NULL);
	mciSendString(TEXT("open \"sms3.mp3\" type mpegvideo alias mp3"), NULL, 0, NULL);
	mciSendString(TEXT("open \"sms1.mp3\" type mpegvideo alias mp3"), NULL, 0, NULL);
	mciSendString(TEXT("open \"sms2.mp3\" type mpegvideo alias mp3"), NULL, 0, NULL);


	v v_;

	setlocale(LC_ALL, "RU-ru");
	srand(time(NULL));

	SetColor(7, 0);

	rools();

	mciSendString(TEXT("play background_music.mp3 repeat"), NULL, 0, NULL);
	questions(v_);

	mciSendString(TEXT("close background_music.mp3"), NULL, 0, NULL);

	system("cls");
	end(v_);

	return 0;
}

#include <graphic.h>

int load_bg()
{
	SDL_Surface* loadedImage;
	loadedImage = SDL_LoadBMP("img/bg.bmp");
	if (loadedImage == 0)
		return -1;
	gd.bg_img = SDL_DisplayFormat(loadedImage);
	SDL_FreeSurface(loadedImage);
	if (gd.bg_img == 0)
		return -1;
	return 0;
}

int load_images()
{
	int index = 0;
	char *filename = (char *)malloc(sizeof(char) * 256);
	SDL_Surface* loadedImage;
	Uint32 color_key;

	while (index < IMG_NBR)
	{
		sprintf(filename, "img/img_%i.bmp", index);
		loadedImage = SDL_LoadBMP(filename);
		if (loadedImage == 0)
			return -1;
		gd.img[index] = SDL_DisplayFormat(loadedImage);
		SDL_FreeSurface(loadedImage);
		loadedImage = NULL;
		if (gd.img[index] == 0)
			return -1;
		color_key = SDL_MapRGB(gd.img[index]->format, 0, 0, 0);
		SDL_SetColorKey(gd.img[index], SDL_SRCCOLORKEY, color_key);
		index++;
	}
	free(filename);
	return load_bg();
}


#ifndef _TEXTURES_H_
#define _TEXTURES_H_


/* Image type - contains height, width, and data */
typedef struct {
    unsigned long sizeX;
    unsigned long sizeY;
    char *data;
} Image;


class COGLTexture
{
public:
	Image *img;
	unsigned int GetID();
	void LoadFromFile(char *filename);
	void SetActive();
	float GetWidth();
	float GetHeight();
private:
	int Width, Height;
	unsigned int ID;
};
#endif
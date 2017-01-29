#pragma once
#include "GLTexture.h"
#include <string>
namespace Piston {

	class ImageLoader
	{
	public:
		static GLTexture loadPNG(std::string filePath);
	};
}


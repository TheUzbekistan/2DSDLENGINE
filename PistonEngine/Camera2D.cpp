#include "Camera2D.h"

namespace Piston {

	Camera2D::Camera2D() : _position(0, 0), _cameraMatrix(1.0f), _scale(1.0f), _needsMatrixUpdate(true), _screenHeight(500), _screenWidth(500), _orthoMatrix(1.0f)
	{
	}


	Camera2D::~Camera2D()
	{
	}

	void Camera2D::init(int screenWidth, int screenHeight)
	{
		_screenWidth = screenWidth;
		_screenHeight = screenHeight;
		_orthoMatrix = glm::ortho(0.0f, (float)_screenWidth, 0.0f, (float)_screenHeight);
	}


	void Camera2D::update()
	{
		if (_needsMatrixUpdate)
		{
			glm::vec3 translate(-_position.x + _screenWidth / 2,-_position.y +_screenHeight / 2, 0.0f);
			_cameraMatrix = glm::translate(_orthoMatrix, translate);
			glm::vec3 scale(_scale, _scale, 0.0f);
			_cameraMatrix = glm::scale(glm::mat4(1.0f), scale) * _cameraMatrix;
			_needsMatrixUpdate = false;
		}
	}
	void Camera2D::convertScreenToWorld(glm::vec2& screenCoords)
	{
		
		screenCoords.x -= _screenWidth / 2;
		screenCoords.y -= _screenHeight / 2;
		screenCoords /= _scale;
		screenCoords += _position;
		
	}
}

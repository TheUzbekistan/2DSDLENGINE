#pragma once
#include <GL/glew.h>
namespace Piston {
	struct Color {
		Color() : r(0), g(0), b(0), a(0) {}
		GLubyte r;
		GLubyte g;
		GLubyte b;
		GLubyte a;
	};
	struct Vertex {
		struct Position {
			float x;
			float y;

		} position;

		struct UV {
			float u;
			float v;

		}uv;

		 Color color;

		void setPosition(float x, float y)
		{
			position.x = x;
			position.y = y;
		}

		void setColor(GLubyte r, GLubyte g, GLubyte b, GLubyte a)
		{
			color.r = r;
			color.g = g;
			color.b = b;
			color.a = a;
		}

		void  setUV(float u, float v)
		{
			uv.u = u;
			uv.v = v;
		}
	};
}

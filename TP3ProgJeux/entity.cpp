#include "entity.h"


entity::entity(Vector2f position) : is_active_(true), health_(1)
{
}


void entity::update(RenderWindow& main_win)
{
}

bool entity::load_textures(const char entity_texture_path[], Texture& texture_)
{
	if(!texture_.loadFromFile(entity_texture_path))
	{
		return false;
	}
	return true;
}

bool entity::entity_pixel_perfect_collision_detection(entity& autre_entity)
{
	FloatRect Intersection;
	Vector2f allo =autre_entity.getPosition();

	if (this->getGlobalBounds().intersects(autre_entity.getGlobalBounds(), Intersection))
	{
		IntRect thisSubRect = this->getTextureRect();
		IntRect autreSubRect = autre_entity.getTextureRect();

		unsigned char* mask1 = bitmasks.getMask(this->getTexture());
		unsigned char* mask2 = bitmasks.getMask(autre_entity.getTexture());

		// Loop through our pixels
		for (int i = Intersection.left; i < Intersection.left + Intersection.width; i++)
		{
			for (int j = Intersection.top; j < Intersection.top + Intersection.height; j++)
			{

				Vector2f thisVector = this->getInverseTransform().transformPoint(i, j);
				Vector2f autreVector = autre_entity.getInverseTransform().transformPoint(i, j);

				// Make sure pixels fall within the sprite's subrect
				if (thisVector.x > 0 && thisVector.y > 0 && autreVector.x > 0 && autreVector.y > 0 &&
					thisVector.x < thisSubRect.width && thisVector.y < thisSubRect.height &&
					autreVector.x < autreSubRect.width && autreVector.y < autreSubRect.height)
				{
					if (bitmasks.getPixel(mask1, this->getTexture(), (int)(thisVector.x) + thisSubRect.left, (int)(thisVector.y) + thisSubRect.top) > 0 &&
						bitmasks.getPixel(mask2, autre_entity.getTexture(), (int)(autreVector.x) + autreSubRect.left, (int)(autreVector.y) + autreSubRect.top) > 0)
						return true;

				}
			}
		}
	}
	return false;
}

bool entity::contains(Vector2f point) const
{
	return getGlobalBounds().contains(point);
}

int entity::get_health()
{
	return health_;
}

void entity::set_health(int health)
{
	health_ = health;
}

void entity::health_check()
{
	if (health_ <= 0)
	{
		is_active_ = false;
	}
}

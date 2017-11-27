#pragma once
#include "entity.h"

const enum tile_type
{
	empty,
	wall,
};

class tile : public entity
{
public :
	//Overload Constructor
	tile(Vector2f position, tile_type tile);

	// Mutators
	/// <summary>
	/// Initialise les textures statiques des tuiles.
	/// </summary>
	/// <returns>Retourne vrai ou faux, dépendant du chargement des textures.</returns>
	static bool load_textures(const char texture_path[]);
	
	/// <summary>
	///Sets the visual adjustments.
	/// </summary>
	void visual_adjustments();

	/// <summary>
	/// Définit la texture de la tuile.
	/// </summary>
	void set_texture(int *map, int scene_width, int scene_height);

	// Accessors
	/// <summary>
	/// Retourne le type de tuile.
	/// </summary>
	/// <returns>Le type de tuile.</returns>
	tile_type get_tile_type() const;

private:
	static Texture texture_;
	IntRect* int_rects_tiles_;
	tile_type tile_type_;
	Vector2f position_;
};


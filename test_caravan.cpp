/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			test_caravan.c
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/
#include "general.h"
#include "caravan.h"

#include "test_caravan.h"

/******************************************************************************
 * create_caravan: 11, 20
 *
 *
 ******************************************************************************/
 TEST(create_caravan)
 {
   init_free_list();

   Caravan gobi_express = new_caravan();
   ASSERT_TRUE(gobi_express != 0, "gobi_express expected to be NOT 0");
   ASSERT_EQUALS(0, get_length(gobi_express));

   delete_caravan(gobi_express);
   ASSERT_TRUE(get_free_list()[0] == gobi_express, "gobi_express expected to be in free list");
 }

 /******************************************************************************
  * add_pack_animal: 20, 21, 22
  *
  *
  ******************************************************************************/
TEST(add_pack_animal)
{
  init_free_list();

  Caravan gobi_express = new_caravan();
  add_pack_animal(gobi_express, 0);
  ASSERT_EQUALS(0, get_length(gobi_express));

  PackAnimal willi = new_camel("Willi", 15);
  PackAnimal mitzi = new_horse("Mitzi", 40);

  add_pack_animal(gobi_express, willi);
  ASSERT_EQUALS(1, get_length(gobi_express));
  ASSERT_TRUE(get_caravan(willi) == gobi_express, "Expected Willi's caravan to be gobi express");

  add_pack_animal(gobi_express, mitzi);
  ASSERT_EQUALS(2, get_length(gobi_express));
  ASSERT_TRUE(get_caravan(mitzi) == gobi_express, "Expected Mitzi's caravan to be gobi express");

  delete_caravan(gobi_express);
  ASSERT_EQUALS(3, get_free_list_length());
  ASSERT_TRUE(get_free_list()[2] == gobi_express, "Last freed pointer expected to be gobi_express");

  delete_animal(willi);
  delete_animal(mitzi);
}

/******************************************************************************
 * test_remove_pack_animal: 25
 *
 *
 ******************************************************************************/
TEST(remove_pack_animal)
{
  init_free_list();

  Caravan gobi_express = new_caravan();

  PackAnimal willi = new_camel("Willi", 15);
  PackAnimal mitzi = new_horse("Mitzi", 40);
  PackAnimal franzi = new_camel("Franzi", 10);

  add_pack_animal(gobi_express, willi);
  add_pack_animal(gobi_express, mitzi);

  remove_pack_animal(gobi_express, franzi);
  ASSERT_EQUALS(2, get_length(gobi_express));
  ASSERT_EQUALS(0, get_free_list_length());

	remove_pack_animal(gobi_express, willi);
  ASSERT_EQUALS(1, get_length(gobi_express));
  ASSERT_EQUALS(1, get_free_list_length());
	ASSERT_TRUE(get_caravan(willi) == 0, "Willi's caravan expected to be 0");

	remove_pack_animal(gobi_express, mitzi);
  ASSERT_EQUALS(0, get_length(gobi_express));
  ASSERT_EQUALS(2, get_free_list_length());
	ASSERT_TRUE(get_caravan(mitzi) == 0, "Mitzi's caravan expected to be 0");

  delete_caravan(gobi_express);
  delete_animal(willi);
  delete_animal(mitzi);
  delete_animal(franzi);
}

/******************************************************************************
 * add_pack_animal_twice: 23
 *
 *
 ******************************************************************************/
TEST(add_pack_animal_twice)
{
  Caravan gobi_express = new_caravan();

  PackAnimal willi = new_camel("Willi", 15);
  add_pack_animal(gobi_express, willi);
  add_pack_animal(gobi_express, willi);
  ASSERT_EQUALS(1, get_length(gobi_express));

  delete_caravan(gobi_express);
  delete_animal(willi);
}

/******************************************************************************
 * caravan_load: 2
 *
 *
 ******************************************************************************/
TEST(caravan_load)
{
  Caravan gobi_express = new_caravan();

  PackAnimal willi = new_camel("Willi", 15);
  add_load(willi, 10);
  add_pack_animal(gobi_express, willi);
  ASSERT_EQUALS(10, get_caravan_load(gobi_express));

  PackAnimal mitzi = new_camel("Mitzi", 40);
  add_load(mitzi, 3);
  add_pack_animal(gobi_express, mitzi);
  ASSERT_EQUALS(13, get_caravan_load(gobi_express));

  remove_pack_animal(gobi_express, mitzi);
  ASSERT_EQUALS(10, get_caravan_load(gobi_express));

  delete_caravan(gobi_express);
  delete_animal(willi);
  delete_animal(mitzi);
}

/******************************************************************************
  * test_unload: 23
  *
  *
  ******************************************************************************/
TEST(unload)
{
  Caravan gobi_express = new_caravan();

  PackAnimal willi = new_camel("Willi", 15);
  add_load(willi, 10);
  add_pack_animal(gobi_express, willi);

  PackAnimal mitzi = new_camel("Mitzi", 40);
  add_load(mitzi, 3);
  add_pack_animal(gobi_express, mitzi);

	unload(gobi_express);
  ASSERT_EQUALS(0, get_load(willi));
  ASSERT_EQUALS(0, get_load(mitzi));
}

/******************************************************************************
 * test_caravan_speed: 2
 *
 * tests caravan_speed
 ******************************************************************************/
TEST(caravan_speed)
{
  Caravan gobi_express = new_caravan();

  PackAnimal willi = new_camel("Willi", 15);
  add_load(willi, 10);
  add_pack_animal(gobi_express, willi);

  PackAnimal mitzi = new_horse("Mitzi", 40);
  add_load(mitzi, 3);
  add_pack_animal(gobi_express, mitzi);

  PackAnimal franzi = new_camel("Franzi", 14);
  add_load(franzi, 5);
  add_pack_animal(gobi_express, franzi);

	add_pack_animal(gobi_express, willi);
	add_pack_animal(gobi_express, mitzi);
	add_pack_animal(gobi_express, franzi);

	ASSERT_EQUALS(5, get_caravan_speed(gobi_express));

  delete_caravan(gobi_express);
  delete_animal(willi);
  delete_animal(mitzi);
  delete_animal(franzi);
}

/******************************************************************************
 * change_caravan: 2
 *
 *
 ******************************************************************************/
TEST(change_caravan)
{
  Caravan gobi_express = new_caravan();
  Caravan sahara_express = new_caravan();

  PackAnimal willi = new_camel("Willi", 15);
  PackAnimal mitzi = new_horse("Mitzi", 35);
  PackAnimal habschi = new_camel("Habschi", 16);
  PackAnimal sissi = new_camel("Sissi", 14);
  PackAnimal franzi = new_camel("Franzi", 20);

	add_pack_animal(gobi_express, willi);
	add_pack_animal(gobi_express, mitzi);
	add_pack_animal(gobi_express, habschi);
	add_pack_animal(gobi_express, sissi);
	add_pack_animal(sahara_express, franzi);

	remove_pack_animal(gobi_express, willi);
	ASSERT_EQUALS(3, get_length(gobi_express));
	ASSERT_TRUE(get_caravan(willi) == 0, "Willi's caravane expected to be 0");

	add_pack_animal(sahara_express, willi);
	ASSERT_EQUALS(2, get_length(sahara_express));
	ASSERT_TRUE(get_caravan(willi) == sahara_express, "Willi's caravane expeced to be sahara_express");

	add_pack_animal(sahara_express, mitzi);
	ASSERT_TRUE(get_caravan(mitzi) == sahara_express, "Mitzi's caravan expected to be sahara_express");
	ASSERT_EQUALS(2, get_length(gobi_express));
	ASSERT_EQUALS(3, get_length(sahara_express));
}

/******************************************************************************
 * test_optimize_load
 *
 *
 ******************************************************************************/
TEST(optimize_load)
{
  Caravan gobi_express = new_caravan();

  PackAnimal willi = new_camel("Willi", 15);
  PackAnimal mitzi = new_horse("Mitzi", 35);
  PackAnimal habschi = new_camel("Habschi", 16);
  PackAnimal sissi = new_camel("Sissi", 14);

  add_load(willi, 4);
  add_load(mitzi, 3);
  add_load(sissi, 10);

	add_pack_animal(gobi_express, willi);
	add_pack_animal(gobi_express, mitzi);
	add_pack_animal(gobi_express, habschi);
	add_pack_animal(gobi_express, sissi);

	ASSERT_EQUALS(11, get_actual_speed(willi));
  ASSERT_EQUALS(5, get_actual_speed(mitzi));
  ASSERT_EQUALS(16, get_actual_speed(habschi));
  ASSERT_EQUALS(4, get_actual_speed(sissi));
  ASSERT_EQUALS(4, get_caravan_speed(gobi_express));

	// optimize_load(gobi_express);
	// assert(caravan_speed(&gobi_express) == 10, tc, "Caravan speed expected to be 10");
	// assert(actual_speed(&willi) == 10, tc, "Willi's speed expected to be 10");
	// assert(actual_speed(&mitzi) == 15, tc, "Mitzi's speed expected to be 15");
	// assert(actual_speed(&habschi) == 10, tc, "Habschi's speed expected to be 10");
	// assert(actual_speed(&sissi) == 10, tc, "Sissi's speed expected to be 10");
}

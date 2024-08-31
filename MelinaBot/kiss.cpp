#include "high_five.h"
#include "command.h"
#include "gif_randomizer.h"

void handle_kiss(dpp::cluster& bot, const dpp::slashcommand_t& event) {




	/*mentioned user*/
	dpp::snowflake userTarget = std::get<dpp::snowflake>(event.get_parameter("mention"));
	std::string userTargetReal = "<@" + userTarget.str() + ">";

	/*mentioning user*/
	dpp::user author = event.command.get_issuing_user();
	std::string authorCheck = author.get_mention().c_str();

	int res = authorCheck.compare(userTargetReal);

	if (res != 0) {

		/*grab kissing gifs*/
		std::string Kgif = handle_Kgif();

		/*creating embed*/
		dpp::embed embed = dpp::embed()
			.set_color(dpp::colors::pink)
			.set_description(author.get_mention() + " kissed " + userTargetReal + "!")
			.set_image(Kgif)
			.set_timestamp(time(0));

		/*posts command to Discord*/
		dpp::message msg(event.command.channel_id, embed);
		event.reply(msg);
	
	}
	else {

		/*if user mentions themselves then it will send a witty message*/
		dpp::embed embed = dpp::embed()
			.set_color(dpp::colors::pink_cupcake)
			.set_description("You will find someone one day :)");

		dpp::message msg(event.command.channel_id, embed);
		event.reply(msg);
			
	}



}
#include "slap.h"
#include "command.h"
#include "gif_randomizer.h"

void handle_slap(dpp::cluster& bot, const dpp::slashcommand_t& event) {


	/*mentioned user*/
	dpp::snowflake userTarget = std::get<dpp::snowflake>(event.get_parameter("mention"));
	std::string userTargetReal = "<@" + userTarget.str() + ">";

	/*mentioning user*/
	dpp::user author = event.command.get_issuing_user();
	std::string authorCheck = author.get_mention().c_str();

	int res = authorCheck.compare(userTargetReal);

	if (res != 0) {

		/*grab slapping gifs*/
		std::string Sgif = handle_Sgif();

		/*creating embed*/
		dpp::embed embed = dpp::embed()
			.set_color(dpp::colors::pink)
			.set_description(author.get_mention() + " slapped " + userTargetReal + "!")
			.set_image(Sgif)
			.set_timestamp(time(0));

		/*posts command to Discord*/
		dpp::message msg(event.command.channel_id, embed);
		event.reply(msg);
	
	}
	else {

		/*if user mentions themselves then the bot sends a special message*/
		dpp::embed embed = dpp::embed()
			.set_color(dpp::colors::pink_cupcake)
			.set_description(author.get_mention() + " slapped themself!");

		dpp::message msg(event.command.channel_id, embed);
		event.reply(msg);

	}
}
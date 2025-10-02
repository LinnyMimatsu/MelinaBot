#include "Include/high_five.h"
#include "Include/command.h"
#include "Include/gif_randomizer.h"

void handle_high_five(dpp::cluster& bot, const dpp::slashcommand_t& event) {


	
			/*mentioned user*/
			dpp::snowflake userTarget = std::get<dpp::snowflake>(event.get_parameter("mention"));
			std::string userTargetReal = "<@" + userTarget.str() + ">";

		
			/*mentioning user*/
			dpp::user author = event.command.get_issuing_user();
			std::string authorCheck = author.get_mention().c_str();
			
			int res = authorCheck.compare(userTargetReal);

			if (res != 0) {
				/*grab high five image*/
				std::string HFgif = handle_HFgif();

				/*creating embed*/
				dpp::embed embed = dpp::embed()
					.set_color(dpp::colors::pink)
					.set_description(author.get_mention() + " high fived " + userTargetReal + "!")
					.set_image(HFgif)
					.set_timestamp(time(0));

				/*embed reply*/
				dpp::message msg(event.command.channel_id, embed);
				event.reply(msg);
			} else {

				dpp::embed embed = dpp::embed()
					.set_color(dpp::colors::pink_cupcake)
					.set_description("I can high five you :(");

				dpp::message msg(event.command.channel_id, embed);
				event.reply(msg);

			}



}
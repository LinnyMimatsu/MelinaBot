#include "high_five.h"
#include "command.h"

void handle_high_five(dpp::cluster& bot, const dpp::user_context_menu_t& event) {


			/*mentioned user*/
			dpp::user user = event.get_user();
			/*mentioning user*/
			dpp::user author = event.command.get_issuing_user();

			/*creating embed*/
			dpp::embed embed = dpp::embed()
				.set_color(dpp::colors::pink)
				.set_description(author.get_mention() + " high fived " + user.get_mention() + "!")
				.set_image("https://i.imgur.com/VaynTWU.gif")
				.set_timestamp(time(0));

			/*embed reply*/
			dpp::message msg(event.command.channel_id, embed);
			event.reply(msg);




}
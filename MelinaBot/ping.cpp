#include "ping.h"
#include "command.h"


void handle_ping(dpp::cluster& bot, const dpp::slashcommand_t& event) {
	

	event.reply(
		dpp::message().add_embed(
			dpp::embed().
			set_color(dpp::colors::yellow).
			set_title("Pong!")


		)
	);

}
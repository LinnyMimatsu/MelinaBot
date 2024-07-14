#include <iostream>
#include <command.h>
#include <heart.h>


void handle_heart(dpp::cluster& bot, const dpp::slashcommand_t& event) {
	
	/*grabbing co_mentionable user and converting their ID to a mention*/
	dpp::snowflake userTarget = std::get<dpp::snowflake>(event.get_parameter("mention"));
	std::string userTargetReal = "<@" + userTarget.str() + ">";
	/*grabbing command author*/
	dpp::user author = event.command.get_issuing_user();
	
	/*creating embed*/
	dpp::embed embed = dpp::embed()
		.set_color(dpp::colors::pink_cupcake)
		.set_description(author.get_mention() + " hearted " + userTargetReal + "! :heart:");
	dpp::message msg(event.command.channel_id, embed);

	/*returns a reply to Discord*/
	event.reply(msg);


	
}
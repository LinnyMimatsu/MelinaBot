#include "embed.h"
#include "command.h"


void handle_embed(dpp::cluster& bot, const dpp::slashcommand_t& event) {
			

	dpp::permission perms = event.command.get_resolved_permission(event.command.usr.id);

	if (perms.can(dpp::p_administrator)) {


		dpp::embed embed = dpp::embed()
			.set_color(dpp::colors::sti_blue)
			.set_title("Some name")
			.set_url("https://somedevsight.dev")
			.set_author("Some name", "https://dpp.dev/", "https://dpp.dev/DPP-Logo.png")
			.set_description("some description here")
			.set_thumbnail("https://dpp.dev/DPP-Logo.png")
			.add_field(
				"regular field title",
				"Some value here"
			)
			.add_field(
				"Inline field title",
				"Some value here",
				true
			)
			.add_field(
				"inline field title",
				"Some value here",
				true
			)
			.set_image("https://dpp.dev/DPP-Logo.png")
			.set_footer(
				dpp::embed_footer()
				.set_text("Some footer text here")
				.set_icon("https://dpp.dev/DPP-Logo.png")
			)
			.set_timestamp(time(0));

		dpp::message msg(event.command.channel_id, embed);

		event.reply(msg);

	}
	else {
		
		dpp::embed embed = dpp::embed()
			.set_color(dpp::colors::pink_cupcake)
			.set_description("You can't use that command!");
		
		dpp::message msg(event.command.channel_id, embed);
		event.reply(msg);

	}

}
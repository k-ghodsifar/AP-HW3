CREATE TABLE Users(
	id SERIAL ,
	telegram_id VARCHAR(255) PRIMARY KEY,
	phone INTEGER  NOT NULL,
    email VARCHAR(255) NOT NULL,
    password VARCHAR(255) NOT NULL,
    first_name VARCHAR(255) NOT NULL,
    last_name VARCHAR(255) NOT NULL,
    vertification_code VARCHAR(255) NOT NULL,
    profile_picture_id SERIAL,
    created_at TIMESTAMP NOT NULL,
    updated_at TIMESTAMP NOT NULL
);

CREATE TABLE BlockUser(
	blocker_user_id VARCHAR(255) UNIQUE,
	blocked_user_id VARCHAR(255) UNIQUE,
	created_at TIMESTAMP NOT NULL,
    FOREIGN KEY (blocker_user_id) REFERENCES Users (telegram_id),
    FOREIGN KEY (blocked_user_id) REFERENCES Users (telegram_id),
    PRIMARY KEY(blocker_user_id,blocked_user_id)
);

CREATE TABLE Message(
	id serial UNIQUE,
	sender_id VARCHAR(255) UNIQUE,
	receiver_id VARCHAR(255) UNIQUE,
	message_text VARCHAR(255),
	created_at TIMESTAMP NOT NULL,
	updated_at TIMESTAMP NOT NULL,
	message_type VARCHAR(100),
	check(message_type in ('voice','video','picture','text')),
	PRIMARY KEY(sender_id,receiver_id,id),
	FOREIGN KEY(sender_id) REFERENCES Users (telegram_id),
	FOREIGN KEY (receiver_id) REFERENCES Users(telegram_id)
);

CREATE TABLE Channel(
	id serial ,
	telegram_id VARCHAR(255) PRIMARY KEY,
	title VARCHAR(255) NOT NULL,
	info VARCHAR(255),
	creater_id VARCHAR(255) UNIQUE,
	created_at TIMESTAMP NOT NULL,
	updated_at TIMESTAMP NOT NULL,
	FOREIGN KEY(creater_id) REFERENCES Users(telegram_id)
);

CREATE TABLE Group(
	id serial,
	join_url VARCHAR(255) PRIMARY KEY,
	creater_id VARCHAR(255) NOT NULL UNIQUE,
    title VARCHAR(255),
    created_at TIMESTAMP NOT NULL,
    updated_at TIMESTAMP NOT NULL,
    FOREIGN KEY(creater_id) REFERENCES Users(telegram_id)
);

CREATE TABLE GroupMessage(
	id serial,
	group_id VARCHAR(255),
	sender_id VARCHAR(255) NOT NULL UNIQUE,
    message_type VARCHAR(255) NOT NULL,
    message_text VARCHAR(255),
    created_at TIMESTAMP NOT NULL,
    updated_at TIMESTAMP NOT NULL,
    check(message_type in ('voice','video','picture','text')),
    FOREIGN KEY(group_id) REFERENCES Group(join_url),
    PRIMARY KEY(group_id,id)
);

CREATE TABLE ChannelMessage(
	id serial,
	channel_id VARCHAR(255) UNIQUE,
    message_type VARCHAR(255) NOT NULL,
    message_text VARCHAR(255),
    created_at TIMESTAMP NOT NULL,
    updated_at TIMESTAMP NOT NULL,
    check(message_type in ('voice','video','picture','text')),
    FOREIGN KEY(channel_id) REFERENCES Channel(telegram_id),
    PRIMARY KEY(channel_id,id)
);

CREATE TABLE MessageAttachment(
	message_id serial UNIQUE,
	attachment_url VARCHAR(255) NOT NULL,
	attachment_thumb_url VARCHAR(255) NOT NULL,
	FOREIGN KEY (message_id) REFERENCES Message(id),
	PRIMARY KEY(attachment_url,message_id)
);

CREATE TABLE ChannelMessageAttachment(
	message_id serial UNIQUE,
	attachment_url VARCHAR(255) NOT NULL,
	attachment_thumb_url VARCHAR(255) NOT NULL,
	FOREIGN KEY (message_id) REFERENCES MessageAttachment(message_id),
	PRIMARY KEY(attachment_url,message_id)
);

CREATE TABLE GroupMessageAttachment(
	message_id serial UNIQUE,
	attachment_url VARCHAR(255) NOT NULL,
	attachment_thumb_url VARCHAR(255) NOT NULL,
	FOREIGN KEY (message_id) REFERENCES MessageAttachment(message_id),
	PRIMARY KEY(attachment_url,message_id)
);

CREATE TABLE GroupMembership(
	user_id VARCHAR(255) NOT NULL,
	group_id VARCHAR(255) NOT NULL,
	created_at TIMESTAMP NOT NULL,
	FOREIGN KEY(user_id) REFERENCES Users(telegram_id),
	FOREIGN KEY(group_id) REFERENCES Group(join_url),
	PRIMARY KEY(user_id,group_id)
);


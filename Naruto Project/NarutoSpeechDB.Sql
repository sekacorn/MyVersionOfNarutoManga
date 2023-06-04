
-- Author: Cornelius S

/*Note: You can use any database application, but I recommend Oracle. This sql file  file creates empty tables. You can choose to add speech late but so far it serves as a foundation that can be used to add speech later or as you can choose. */


-- Create Speech database
CREATE DATABASE Speech;



-- Create ConversationInEnglish table
CREATE TABLE ConversationInEnglish (
    id NUMBER PRIMARY KEY,
    Speech VARCHAR2(255),
    OwnerOftheSpeech VARCHAR2(255),
    TrashTalkingTechniques VARCHAR2(255)
);


-- Create ConversationInJapanese table
CREATE TABLE ConversationInJapanese (
    id NUMBER PRIMARY KEY,
    Speech VARCHAR2(255),
    OwnerOftheSpeech VARCHAR2(255),
    TrashTalkingTechniques VARCHAR2(255)
);

-- Create ConversationInLuganda table
CREATE TABLE ConversationInLuganda (
    id NUMBER PRIMARY KEY,
    Speech VARCHAR2(255),
    OwnerOftheSpeech VARCHAR2(255),
    TrashTalkingTechniques VARCHAR2(255)
);

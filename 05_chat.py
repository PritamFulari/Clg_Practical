pip install nltk



import nltk
from nltk.chat.util import Chat, reflections




patterns = [
    (r'hi|hello|hey', ['Hello!', 'Hi there!', 'Hey!']),
    (r'how are you?', ['I am good, thank you!', 'I am doing well, how about you?']),
    (r'i\'m (.*)', ['Nice to hear that. How can I assist you today?']),
    (r'(.*) (age|old) are you?', ['I am just a computer program, I don\'t have an age.']),
    (r'what can you do for me?', ['I can assist you with basic queries. Just ask!']),
    (r'quit', ['Bye, take care!']),
]




chatbot = Chat(patterns, reflections)


print("Welcome! Type quit to end the conversation.")
while True:
    user_input = input("You: ")
    response = chatbot.respond(user_input)
    print("Bot:", response)
    if user_input.lower() == 'quit':
        break

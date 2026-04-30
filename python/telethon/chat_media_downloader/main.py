import asyncio
import os
import re

from telethon import TelegramClient
from tqdm import tqdm

API_ID = os.environ.get("API_ID")
API_HASH = os.environ.get("API_HASH")

def sanitize_filepath(name):
    # Removes characters that are illegal for folder names
    return re.sub(r'[\\/*?:"<>|]', "", name)

async def main():
    if not API_ID or not API_HASH:
        print("Error: API_ID or API_HASH environment variables are missing.")
        return
    
    async with TelegramClient("session", API_ID, API_HASH) as client:
        print("Fetching dialogs...")
        dialogs = await client.get_dialogs()
        
        # Display available chats to the user
        for i, dialog in enumerate(dialogs):
            print(f"[{i}] {dialog.title}")

        # Input handling
        user_input = input("\nEnter chat title or index: ")
        
        target_chat = None
        final_title = ""

        # Logic to handle both index selection and title matching
        if user_input.isdigit() and int(user_input) < len(dialogs):
            index = int(user_input)
            target_chat = dialogs[index].entity
            final_title = dialogs[index].title
        else:
            for dialog in dialogs:
                if dialog.title == user_input:
                    target_chat = dialog.entity
                    final_title = dialog.title
                    break
        
        if not target_chat:
            print(f"Error: Chat '{user_input}' not found.")
            return

        print(f"Fetching messages for '{final_title}'...")
        messages = await client.get_messages(target_chat, limit=100)
        
        media_messages = [m for m in messages if m.media]
        print(f"Found {len(media_messages)} media items.")

        # Sanitize folder name
        safe_folder = sanitize_filepath(final_title)
        os.makedirs(f"./{safe_folder}/", exist_ok=True)

        for message in tqdm(media_messages, desc="Downloading"):
            # client.download_media is generally more stable for bulk tasks
            await client.download_media(message, file=f"./{safe_folder}/")

if __name__ == "__main__":
    try:
        asyncio.run(main())
    except KeyboardInterrupt:
        print("\nInterrupted by user.")